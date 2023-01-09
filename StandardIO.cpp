//
// Created by kashann on 09/01/2023.
//

//
// Created by kashann on 09/01/2023.
//

#include "StandardIO.h"

StandardIO::StandardIO() : DefaultIO() {


}

std::string StandardIO::read() {
    std::string input;
    std::getline(std::cin, input);
    return input;
}

void StandardIO::write(std::string output) {
    std::cout << output << std::endl;
}

