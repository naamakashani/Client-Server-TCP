

#ifndef EX4_CHOOSEFIVE_H
#define EX4_CHOOSEFIVE_H


#include "Command.h"
#include <unistd.h>
class chooseFive : public Command{

    void execute();

public:
    chooseFive(Data *data, std::string description, DefaultIO* dio);
};


#endif //EX4_CHOOSEFIVE_H
