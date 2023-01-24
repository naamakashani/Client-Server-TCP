//
// Created by kashann on 09/01/2023.
//

//
// Created by kashann on 08/01/2023.
//
#ifndef EX4_CHOOSEONE_H
#define EX4_CHOOSEONE_H

#include "Command.h"
#include <unistd.h>
class chooseOne : public Command {
public:
    chooseOne(Data *data, std::string description, DefaultIO *dio);

    void execute();
    void writeToFile(std::string& fileContent, std::string filePath);
};


#endif //EX4_CHOOSEONE_H
