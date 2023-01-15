//
// Created by kashann on 09/01/2023.
//


#include "CLI.h"
#include "chooseOne.h"
#include "chooseTwo.h"
#include "chooseThree.h"
#include "chooseFour.h"
#include "chooseFive.h"
#include "StandardIO.h"
#include "SocketIO.h"
#include <array>
#include <unistd.h>

CLI::CLI(int client_s) {
    Data *c = new Data();
    DefaultIO *dio = new SocketIO(client_s);
    //DefaultIO *dio = new StandardIO();
    std::array<Command *, 5> commands{
            new chooseOne(c, "1", dio),
            new chooseTwo(c, "2", dio),
            new chooseThree(c, "3", dio),
            new chooseFour(c, "4", dio),
            new chooseFive(c, "5", dio)
    };
    m_commands = commands;
    m_IO = dio;
}

void CLI::start() {
    std::string stringMenu = "Welcome to KNN Classifier Server. Please choose an option:\n1. upload an unclassified csv data file\n2. algorithm setting\n3. classify data\n4. display results\n5. download results\n8.exit";
    int flag = 1;
    while (flag) {
        sleep(1);
        m_IO->write(stringMenu);
        std::string buffer = m_IO->read();
        int num = stoi(buffer);
        switch (num) {
            case 1:
                m_commands[0]->execute();
                break;
            case 2:
                m_commands[1]->execute();
                break;
            case 3:
                m_commands[2]->execute();
                break;
            case 4:
                m_commands[3]->execute();
                break;
            case 5:
                m_commands[4]->execute();
                break;
            case 8:
                flag = 0;
                break;
            default:
                break;
        }
    }
}

