#include <iostream>
#include "Menu.h"

int main() {
    Menu *menu = new Menu();
    std::string stringMenu = "Welcome to KNN Classifier Server. Please choose an option:\n1. upload an unclassified csv data file\n2. algorithm setting\n3. classify data\n4. display results\n5. download results\n8.exit";
    int flag = 1;
    while (flag) {
        menu->m_IO->write(stringMenu);
        std::string buffer = menu->m_IO->read();
        int num = stoi(buffer);
        switch (num) {
            case 1:
                menu->m_commands[0]->execute();
                break;
            case 2:
                menu->m_commands[1]->execute();
                break;
            case 3:
                menu->m_commands[2]->execute();
                break;
            case 4:
                menu->m_commands[3]->execute();
                break;
            case 5:
                menu->m_commands[4]->execute();
                break;
            case 8:
                flag = 0;
                break;
            default:
                break;
        }

    }
}















