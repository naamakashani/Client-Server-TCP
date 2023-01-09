//
// Created by kashann on 09/01/2023.
//

#include "Command.h"

Command:: Command(CLI* data,std::string description,DefaultIO *dio){
    m_data=data;
    m_description=description;
    m_dio=dio;
}