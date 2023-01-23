//
// Created by parshas on 11/01/2023.
//

#ifndef EX4AP_CLIENT_H
#define EX4AP_CLIENT_H

#include <iostream>

class Client {
public:
    bool checkValidation(std::string str);

    bool readInput(std::string &input, bool &flag);

    void sendToServer(int sock, std::string message);

    void chooseOne(std::string userInput);

    void talkWithServer();

    void chooseTwo(std::string userInput);

    void chooseThree(std::string basicString);

    void chooseFive(std::string basicString);

    void chooseFour(std::string userInput);

    std::string ReadResult(std::string userInput);

    std::string writetoFile(std::string fileContent, std::string filePath);

    void handleCmd1(int sock);

    void handleCmd1(std::string userInput);
};


#endif //EX4AP_CLIENT_H
