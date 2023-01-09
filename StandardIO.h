//
// Created by kashann on 09/01/2023.
//

#include "DefaultIO.h"

#ifndef EX4_STANDARDIO_H
#define EX4_STANDARDIO_H

class StandardIO : public DefaultIO {
public:
    StandardIO();

    virtual std::string read();

    virtual void write(std::string);
};

#endif //EX4_STANDARDIO_H