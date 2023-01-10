//
// Created by kashann on 08/01/2023.
//

#ifndef EX4_CHOOSEFOUR_H
#define EX4_CHOOSEFOUR_H


#include "Command.h"

class chooseFour : public Command{
public:
    chooseFour(Data *data, std::string description, DefaultIO* dio);
    void execute();
};


#endif //EX4_CHOOSEFOUR_H
