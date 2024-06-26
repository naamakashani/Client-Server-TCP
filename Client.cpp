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
#include <netinet/tcp.h>
#include <unistd.h>
#include <vector>
#include <pthread.h>
#include <fstream>
#include <sstream>
#include <mutex>
#include <thread>

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

std::string filePathGiven(std::string filePath) {
    // open the CSV file
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cout << "invalid input" << std::endl;
    }
    std::string fileContent((std::istreambuf_iterator<char>(file)),
                            std::istreambuf_iterator<char>());
    std::stringstream ss(fileContent);
    std::string line;
    std::string csvContent;

    // parse the CSV file
    while (getline(ss, line)) {
        csvContent += line + '\n';
    }
    return csvContent;
}

bool hasEnding(std::string const &fullString, std::string const &ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}

/***
 *
 * @param vector1
 * @return true after put the string into vector
 */

bool Client::readInput(std::string &input, bool &flag) {
    try {
        getline(std::cin, input);
        if (hasEnding(input, ".csv")) {
            flag = 1;
//            std::cout << "csv file " << std::endl << filePathGiven(input);
//            input = filePathGiven(input);
        }
    }
    catch (...) {
        return false;
    }
    return true;
}


void receiveServer() {
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(sock, buffer, expected_data_len, 0);
    if (read_bytes <= 0) {
        perror("connection closed");
        exit(0);

    } else {
        if(strcmp(buffer,"null") != 0) {
            std::cout << buffer << std::endl;
            std::cout.flush();
        }
    }
}

void Client::sendToServer(int sock, std::string message) {
    int sent_bytes = send(sock, message.c_str(), message.length() + 1, 0);
    //Check if an error occurred while sending to the server:
    if (sent_bytes < 0) {
        //If an error occurred-print a message and close the client:
        std::cout << "Error sending to server" << std::endl;
        close(sock);
        exit(-1);
    }
    //std::cout << "Sent " << sent_bytes << " bytes" << std::endl;
}


void Client::chooseOne(std::string userInput) {
    Client::sendToServer(sock, userInput);
    receiveServer();
    // read csv file name from user
    bool flag = false;
    std::string csvname;

    std::cout.flush();
    readInput(csvname, flag);
    if (!flag) {
        std::cout << "invalid input" << std::endl;
        sendToServer(sock, "invalid input");
    } else {
        std::string data = filePathGiven(csvname);
        sendToServer(sock, data);
        receiveServer();

        // read csv file name from user for test
        flag = false;

        std::cout.flush();
        readInput(csvname, flag);
        if (!flag) {
            std::cout << "invalid input" << std::endl;
            sendToServer(sock, "invalid input");
        } else {
            data = filePathGiven(csvname);
            sendToServer(sock, data);
            receiveServer();
        }
    }
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    return;


}

void Client::chooseTwo(std::string userInput) {
    Client::sendToServer(sock, userInput);
    receiveServer();
    getline(std::cin, userInput);
    if (userInput.empty()) {
        userInput = "enter";
    }
    Client::sendToServer(sock, userInput);
    receiveServer();
}

void Client::chooseThree(std::string userInput) {
    Client::sendToServer(sock, userInput);
    receiveServer();
}

void Client::talkWithServer() {
    std::string userInput;
    flag = 1;
    while (flag == 1) {
        userInput = "";
//        receiveServer();
        std::string stringMenu = "Welcome to KNN Classifier Server. Please choose an option:\n1. upload an unclassified csv data file\n2. algorithm setting\n3. classify data\n4. display results\n5. download results\n8.exit";
        std::cout << stringMenu << std::endl;
        getline(std::cin, userInput);
        if (userInput == "1") {
            Client::chooseOne(userInput);
        }
        if (userInput == "2") {
            Client::chooseTwo(userInput);
        }
        if (userInput == "3") {
            Client::chooseThree(userInput);
        }
        if (userInput == "4") {
            Client::chooseFour(userInput);
            std::cin.tie(0);
            std::ios::sync_with_stdio(0);

        }
        if (userInput == "5") {

            Client::chooseFive(userInput);
        }
        if (userInput == "8") {
            flag = 0;
        } else {
            continue;
        }

    }
}

void Client::writetoFile(std::string fileContent, std::string filePath) {
    std::fstream file;
    file.open(filePath, std::ios::in);
    if (file.good()) {
        file.close();
        file.open(filePath, std::ios::out | std::ios::app | std::ios::binary);
        if (file.good()) {
            file.clear();
            file << fileContent;
            file.close();
        }
    } else {
        file.close();
        file.open(filePath, std::ios::out | std::ios::binary);
        if (file.good()) {
            file.clear();
            file << fileContent;
            file.close();
        }
    }
}

void Client::chooseFour(std::string userInput) {
    std::cout << ReadResult(userInput);
    std::cout << std::endl;

}

std::string Client::ReadResult(std::string userInput) {
    Client::sendToServer(sock, userInput);
    char buffer2[4096];
    int expected_data_len = sizeof(buffer2);    //write the buffer into the file path
    std::string resultContent;
    while (true) {
        int read_bytes = recv(sock, buffer2, expected_data_len, 0);
        if (read_bytes <= 0) {
            perror("connection closed");
            exit(0);

        }
        std::string subFile;
        subFile = buffer2;
        if (subFile.find("*") != std::string::npos) {
            //we need to remove the * from the string
            subFile = subFile.substr(0, subFile.find("*"));
            resultContent += subFile;
            break;
        }
        resultContent += subFile;

    }
    return resultContent;

}

void Client::chooseFive(std::string userInput) {
    std::string resultContent = ReadResult(userInput);
    std::string pathInput;
    getline(std::cin, pathInput);
    std::thread t(&Client::writetoFile, this, resultContent, pathInput);
    t.detach();

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
    int flag = 1;
    setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, (char *) &flag, sizeof(int));
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
    }
    // client connect to server
    client.talkWithServer();
    close(sock);
}
