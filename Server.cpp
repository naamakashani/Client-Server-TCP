//
// Created by parshas on 11/01/2023.
//

#include "Server.h"
#include "knn.h"
#include "CLI.h"

#pragma comment(lib, "ws2_32.lib")

#include <iostream>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <thread>
#include <pthread.h>

const int BACKLOG = 5;
int client_sock;

void *threadFunction(void *threadid) {
    CLI cli = CLI(client_sock);
    cli.start();
    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    pthread_t threads[20];
    //Server server;
    const int port = stoi(argv[1]);
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
    std::cout << "create socket" << endl;

    for (long t = 0; t < 20; t++) {

        // Start listening for incoming connections
        int listen_result = listen(server_socket, BACKLOG);
        if (listen_result < 0) {
            std::perror("Error listening socket");
        }

        struct sockaddr_in client_addr;
        unsigned int addr_len = sizeof(client_addr);
        client_sock = accept(server_socket, (struct sockaddr *) &client_addr, &addr_len);
        if (client_sock < 0) {
            perror("error accepting client");
        }
        std::cout << "a client has connect to server" << endl;
        ///a client has connect to server
        pthread_create(&threads[t], NULL, threadFunction, (void *)t);
        /* thread th1([]() {
             CLI cli = CLI();
             cli.start();
         });*/

    }
    close(server_socket);
    pthread_exit(NULL);


}
