//
// Created by kashann on 09/01/2023.
//

//
// Created by kashann on 08/01/2023.
//
#include <iostream>
#include "DefaultIO.h"
#include "Data.h"

#ifndef EX4_COMMAND_H
#define EX4_COMMAND_H

class Command{
public:
    Data* m_data;
    std::string m_description;
    DefaultIO* m_dio;
    Command(Data* m_data, std::string m_description, DefaultIO* m_dio);
    virtual void execute()=0;
};

#endif //EX4_COMMAND_H