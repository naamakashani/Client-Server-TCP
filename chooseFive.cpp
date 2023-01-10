//
// Created by kashann on 09/01/2023.
//

#include "chooseFive.h"
chooseFive::chooseFive(Data *data, std::string description, DefaultIO* dio) : Command(data, description, dio) {

}

void chooseFive::execute() {
    m_dio->write(m_data->m_labelsString);
}