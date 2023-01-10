//
// Created by kashann on 09/01/2023.
//

//
// Created by kashann on 08/01/2023.
//

#ifndef EX4_CHOOSETWO_H
#define EX4_CHOOSETWO_H


#include "Command.h"

class chooseTwo : public Command{
public:
    chooseTwo(Data* data, std::string description, DefaultIO* dio);
    void execute();

    bool validMetric(std::string dis);


    bool validK(std:: string k);
};


#endif //EX4_CHOOSETWO_H
