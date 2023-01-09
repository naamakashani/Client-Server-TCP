//
// Created by kashann on 09/01/2023.
//

//
// Created by kashann on 08/01/2023.
//

#include "Menu.h"
#include "chooseOne.h"
#include "chooseTwo.h"
#include "chooseThree.h"
#include "chooseFour.h"
#include "chooseFive.h"
#include "StandardIO.h"
#include <array>

Menu::Menu() {
    CLI *c = new CLI();
    DefaultIO *dio = new StandardIO();
    std::array<Command *, 5> commands;
    m_commands=commands;
    m_IO=dio;
    commands[0] = new chooseOne(c, "1", dio);
    commands[1] = new chooseTwo(c, "2", dio);
    commands[2] = new chooseThree(c, "3", dio);
    commands[3] = new chooseFour(c, "4", dio);
    commands[4] = new chooseFive(c, "5", dio);
}

