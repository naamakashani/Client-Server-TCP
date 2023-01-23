//
// Created by kashann on 09/01/2023.
//

#include "chooseOne.h"

#include <iostream>
#include <fstream>


chooseOne:: chooseOne(Data* data, std::string description, DefaultIO* dio) : Command(data, description , dio){

}
//void chooseOne::execute() {
//    m_dio->write("Please upload your local train CSV file.");
//    std::string file;
//    file = m_dio->read();
//    m_data->m_fileTrain=file;
//    m_dio->write("Upload complete.");
//    sleep(1);
//    m_dio->write("Please upload your local test CSV file.");
//    std::string fileTest;
//    sleep(1);
//    fileTest = m_dio->read();
//    m_data->m_fileTest=fileTest;
//    m_dio->write("Upload complete.");
//    sleep(1);
//
//}
//
// Created by kashann on 09/01/2023.
//



std::string chooseOne::writeCSV(std::string fileContent, bool classified) {
    std::string filePath;
    fileContent = fileContent + " ";
    // check if string contain null char, if so delete it.
    size_t pos = fileContent.find('\0');
    size_t finalPos = fileContent.find(" ");
    fileContent = fileContent.substr(pos + 1, finalPos - 1);
    if (classified) {
        filePath = "classified.csv";
    } else {
        filePath = "unClassified.csv";
    }
    std::fstream file;
    file.open(filePath, std::ios::in);
    if (file.good()) {
        std::cout << "File exists, writing to it" << std::endl;
        file.close();
        file.open(filePath, std::ios::out | std::ios::app | std::ios::binary);
        if (file.good()) {
            file.clear();
            file << fileContent;
            file.close();
        }
    } else {
        std::cout << "File does not exist, creating it" << std::endl;
        file.close();
        file.open(filePath, std::ios::out | std::ios::binary);
        if (file.good()) {
            file.clear();
            file << fileContent;
            file.close();
        }
    }
    return filePath;
}

void chooseOne::execute() {

    int k;
    k = m_data->m_k;
    std::string metric;
    metric = m_data->m_metric;
    m_dio->write("Please upload your local train CSV file.");
    std::string subFile;
    //read the data from the client and write to a new file
    //while the client is sending data we need to read it
    std::string trainFileContent;
    while (true) {
        std::string subFile = m_dio->read();
        //check if there is * in sub file if so we need to read until the * and then break
        if (subFile.find("*") != std::string::npos) {
            //we need to remove the * from the string
            subFile = subFile.substr(0, subFile.find("*"));
            trainFileContent += subFile;
            break;
        }
        trainFileContent += subFile;

    }
    std::string trainFile = writeCSV(trainFileContent, true);
    m_data->m_fileTrain = trainFile;
    m_dio->write("Upload complete.");
    sleep(1);
    m_dio->write("Please upload your local test CSV file.");
    std::string subFile2;
    //read the data from the client and write to a new file
    //while the client is sending data we need to read it
    std::string trainFileContent2;
    while (true) {
        std::string subFile2 = m_dio->read();
        //check if there is * in sub file if so we need to read until the * and then break
        if (subFile2.find("*") != std::string::npos) {
            //we need to remove the * from the string
            subFile2 = subFile2.substr(0, subFile2.find("*"));
            trainFileContent2 += subFile2;
            break;
        }
        trainFileContent2 += subFile2;

    }
    std::string testFile = writeCSV(trainFileContent2, false);
    m_data->m_fileTest = testFile;
    m_dio->write("Upload complete.");
    m_data->m_k = k;
    m_data->m_metric = metric;
    std::cout << k << metric << std::endl;



}