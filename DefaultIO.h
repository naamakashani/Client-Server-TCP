//
// Created by kashann on 09/01/2023.
//

#include <iostream>
#ifndef EX4_DEFAULTIO_H
#define EX4_DEFAULTIO_H


class DefaultIO{
public:
    DefaultIO();
    virtual std:: string read()=0;
    virtual void write(std:: string)=0;
};
#endif //EX4_DEFAULTIO_H