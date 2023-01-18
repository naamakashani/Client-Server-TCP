//
// Created by parshas on 11/01/2023.
//

#include "Client.h"
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <vector>
#include <pthread.h>
#include <fstream>
#include <sstream>

int sock;
int flag;

/**
 * check validation of line of data.
 *
 */
bool Client::checkValidation(std::string str) {

    std::vector<float> v1;
    std::string temp = "";
    const char *split = " ";
    if (str.empty()) {
        return false;
    }

// get the vector of numbers
    int i;
    for (i = 0; i < (int) str.size(); i++) {
        if (str[i] != *(split)) {
            if (isdigit(str[i]) or str[i] == '.') {
                temp += str[i];
            } else {
                if (temp != "") {
                    return false;
                } else {
                    break;
                }
            }
        } else {
            if (temp != "" && temp.max_size()) {
                v1.push_back(stod(temp));
                temp = "";
            }
        }

    }
    if (temp != "" && temp.max_size()) {
        v1.push_back(stod(temp));
    }
    if (v1.empty()) {
        return false;
    }
// get the distance
    std::string dis = "";
    int j;
    for (j = i; j < (int) str.size(); j++) {
        if (str[j] != *(split)) {
            dis += str[j];
        } else {
            if (dis == "AUC" || dis == "MAN" || dis == "CHB" || dis == "CAN" || dis == "MIN") {
                break;
            } else {
                return false;
            }
        }
        if (dis.size() > 3) {
            return false;
        }
    }
    if (!isdigit(str[j + 1])) {
        return false;
    }
    if (str[j + 1] <= 0) {
        return false;
    }
    return true;
}

std::string filePathGiven(std::string filePath){
    // open the CSV file
    std::ifstream file("filePath");
    if (!file.is_open()) {
        std::cout << filePath <<std::endl;
        std::cout << "not open" <<std::endl;
        std::cout << "Error: " << strerror(errno) << std::endl;
    }
    std::string fileContent((std::istreambuf_iterator<char>(file)),
                      std::istreambuf_iterator<char>());
    std::stringstream ss(fileContent);
    std::string line;
    std::string csvContent;

    // parse the CSV file
    while (getline(ss, line)) {
        csvContent += line + '\n';
        std::cout << line <<std::endl;
    }
    return csvContent;
}
bool hasEnding (std::string const &fullString, std::string const &ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}

/***
 *
 * @param vector1
 * @return true after put the string into vector
 */

bool Client::readInput(std::string &input) {
    try {
        getline(std::cin, input);
        if (hasEnding(input, ".csv")){
            std::cout << "csv file " << std::endl << filePathGiven(input);
            input = filePathGiven(input);
        }
    }
    catch (...) {
        return false;
    }
    return true;
}

void *threadFunctionRecive(void *threadid) {
    Client client;
    while (flag) {
        char buffer[4096];
        int expected_data_len = sizeof(buffer);
        int read_bytes = recv(sock, buffer, expected_data_len, 0);
        if (strcmp(buffer, "0") == 0) {
            flag = 0;
        } else {
            if (read_bytes <= 0) {
                perror("connection closed");
                exit(0);
                break;
            } else {
                std::cout << buffer << std::endl;
            }
        }
    }
    pthread_exit(NULL);
}

void *threadFunctionsend(void *threadid) {
    Client client;
    std::string userInput = "";
    while (userInput != "8") {
        client.readInput(userInput);
        if (userInput.empty()) {
            userInput = "enter";
        }
        int send_bytes = send(sock, userInput.data(), userInput.length(), 0);
        if (send_bytes < 0) {
            perror("error in sending");
            break;
        }
    }
    flag = 0;
    pthread_exit(NULL);
}


int main(int argc, char **argv) {
    flag = 1;
    Client client;
    const char *ip_address = (argv[1]);
    int port_no = std::stoi(argv[2]);
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error in creating socket");
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
    }
    // client connect to server
    std::cout << "client connect to server" << std::endl;
    pthread_t threadRecive;
    pthread_t threadSend;
    long t1 = 0;
    long t2 = 1;
    pthread_create(&threadRecive, NULL, threadFunctionRecive, (void *) t1);
    pthread_create(&threadSend, NULL, threadFunctionsend, (void *) t2);
    pthread_join(threadRecive, NULL);
    pthread_join(threadSend, NULL);
    close(sock);
}
