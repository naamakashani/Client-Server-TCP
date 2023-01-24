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
    char buffer[10 * 1024] = "";
    std::string msg = "";
    int expected_data_len = sizeof(buffer) - 1; // leave last byte for NUL
    /* The data read may exceed buffer size, so loop till NUL character
    is received */
    while(true) {
        int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
        if (read_bytes == 0) {
                pthread_exit(NULL);
        } else if (read_bytes < 0) {
            std::cerr << "Error reading data from client" << std::endl;
        } else {
            buffer[read_bytes] = '\0';
            msg += buffer; // append to the message
            // check if message is complete
            // read till the terminating NUL byte
            if(buffer[read_bytes-1] == '\0') // is last read byte NUL?
                break;
        }
    }
//    std::cout << "Read " << msg.size() << " bytes" << std::endl;
    return msg;
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
