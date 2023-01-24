//
// Created by kashann on 09/01/2023.
//

#include "chooseOne.h"

#include <iostream>
#include <fstream>


chooseOne:: chooseOne(Data* data, std::string description, DefaultIO* dio) : Command(data, description , dio){

}
void chooseOne::execute() {
    m_dio->write("Please upload your local train CSV file.");
    std::string fileData;
    fileData = m_dio->read();
    // need to generate a filename per thread to save the CSV files
    // names should be such that they MUST BE UNIQUE for every thread
    // m_data object will be unique for every connection so using its
    // address as unsigned number for the file name
    std::string generatedFileName = std::to_string((unsigned long) m_data);

    m_data->m_fileTrain=generatedFileName + ".csv";

    writeToFile(fileData, m_data->m_fileTrain);
    sleep(1);
    // Two consecutive read operations on client side is problematic
    // so avoiding consecutive writes by merging in one
    m_dio->write("Upload complete.\nPlease upload your local test CSV file.");
    std::string testData;
    sleep(1);
    testData = m_dio->read();
    m_data->m_fileTest=generatedFileName + "_test.csv";

    writeToFile(testData, m_data->m_fileTest);

    m_dio->write("Upload complete.");
    sleep(1);

}
void chooseOne::writeToFile(std::string& fileContent, std::string filePath) {
    std::ofstream file;
    file.open(filePath, std::ios::trunc | std::ios::binary);
    if (file.good()) {
        file.clear();
        file << fileContent;
        file.close();
    } else {
	std::cout << "Could not write to " << filePath << std::endl;
    }
}
