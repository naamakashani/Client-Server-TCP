//
// Created by kashann on 09/01/2023.
//

#include "chooseOne.h"

#include <iostream>
#include <unistd.h>

chooseOne:: chooseOne(Data* data, std::string description, DefaultIO* dio) : Command(data, description , dio){

}
void chooseOne::execute() {
    m_dio->write("Please upload your local train CSV file.");
    std::string file;
    file = m_dio->read();
    m_data->m_fileTrain=file;
    m_dio->write("Upload complete.");
    sleep(1);
    m_dio->write("Please upload your local test CSV file.");
    std::string fileTest;
    sleep(1);
    fileTest = m_dio->read();
    m_data->m_fileTest=fileTest;
    m_dio->write("Upload complete.");


}