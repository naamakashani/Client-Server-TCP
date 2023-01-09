//
// Created by kashann on 09/01/2023.
//

//
// Created by kashann on 08/01/2023.
//

#include <array>
#include "Command.h"

#ifndef EX4_MENU_H
#define EX4_MENU_H

#endif //EX4_MENU_H

class Menu {
public:
    std::array<Command *, 5> m_commands;
    DefaultIO* m_IO;
    Menu();
};