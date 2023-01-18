//
// Created by parshas on 11/01/2023.
//

#include "SocketIO.h"
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

SocketIO::SocketIO(int client_s) : DefaultIO() {
    client_sock = client_s;
}

std::string SocketIO::read() {
    char buffer[2056] = "";
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        std::cerr << "connection is closed" << std::endl;
        pthread_exit(NULL);
    } else if (read_bytes < 0) {
        std::cerr << "Error reading data from client" << std::endl;
    }
    return buffer;
}

void SocketIO::write(std::string output) {
    const int length = output.length();

    // declaring character array (+1 for null terminator)
    char* char_array = new char[length + 1];

    // copying the contents of the
    // string to char array
    strcpy(char_array, output.c_str());
    int sent_bytes = send(client_sock, char_array, output.length() + 1, 0);
    if (sent_bytes < 0) {
        perror("error sending to client");
    }
}