//
// Created by kashann on 09/01/2023.
//

//
// Created by kashann on 08/01/2023.
//
#ifndef EX4_CHOOSEONE_H
#define EX4_CHOOSEONE_H

#include "Command.h"

class chooseOne : public Command {
public:
    chooseOne(CLI *data, std::string description, DefaultIO *dio);

    void execute();
};


#endif //EX4_CHOOSEONE_H
