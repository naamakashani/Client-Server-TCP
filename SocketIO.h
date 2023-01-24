//
// Created by parshas on 11/01/2023.
//

#include "DefaultIO.h"
#ifndef EX4AP_SOCKETIO_H
#define EX4AP_SOCKETIO_H


class SocketIO : public DefaultIO {
public:
    int client_sock;
    SocketIO(int client_s);

    virtual std::string read();

    virtual void write(std::string);
};

#endif //EX4AP_SOCKETIO_H
