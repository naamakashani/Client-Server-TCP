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

