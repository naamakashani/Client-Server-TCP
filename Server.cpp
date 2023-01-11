//
// Created by parshas on 11/01/2023.
//

#include "Server.h"
#include "knn.h"

#pragma comment(lib, "ws2_32.lib")

#include <iostream>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>


int main(int argc, char **argv) {

    string path = (argv[1]);
    const int port = stoi(argv[2]);
    // Create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        std::perror("Error creating socket");
    }

    // Set up the sockaddr_in struct
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);

    // Bind the socket to an address and port
    int bind_result = bind(server_socket, (struct sockaddr *) &addr, sizeof(addr));
    if (bind_result < 0) {
        std::perror("Error binding socket");
    }

    // Start listening for incoming connections
    int listen_result = listen(server_socket, BACKLOG);
    if (listen_result < 0) {
        std::perror("Error listening socket");
    }
//server is waiting to clients
    while (true) {
        struct sockaddr_in client_addr;
        unsigned int addr_len = sizeof(client_addr);
        int client_sock = accept(server_socket, (struct sockaddr *) &client_addr, &addr_len);
        if (client_sock < 0) {
            perror("error accepting client");
        }
        ///a client has connect to server
        while (true) {
            string str = "";
            char buffer[2056];
            int expected_data_len = sizeof(buffer);
            int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
            if (read_bytes == 0) {
                break;

            } else if (read_bytes < 0) {
                std::cerr << "Error reading data from client" << std::endl;
            } else {
                //the client sent to the server -1 so the server close the connection
                if (buffer == "-1") {
                    close(client_sock);
                    break;
                }
                std::vector<float> vectorInput;
                std::string dis;
                int k;
                ///convert string to const char *
                const char *met = dis.c_str();
                ///checks the validation of input
                if (readInput(buffer, vectorInput, dis, k)) {
                    KNN knn = KNN(k, path, met);
                    str = findPredict(knn, vectorInput);
                } else {
                    str = "invalid input";
                }
                ///send to client the input
                char classPredict[str.length() + 1];
                for (int x = 0; x < sizeof(str); x++) {
                    classPredict[x] = str[x];
                }
                int sent_bytes = send(client_sock, classPredict, str.length(), 0);
                if (sent_bytes < 0) {
                    perror("error sending to client");
                }
            }
        }
    }
    close(server_socket);

}
