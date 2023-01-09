//
// Created by kashann on 09/01/2023.
//
//
// Created by kashann on 08/01/2023.
//

#ifndef EX4_CLI_H
#define EX4_CLI_H


#include <string>
#include <vector>

class CLI {
public:
    int m_k=5;
    std::string m_metric="EUC";
    std::string m_fileTrain=" ", m_fileTest=" ";
    std::vector<std::string> m_labels={" "};
    std::string m_labelsFile=" ";


    void start();
};


#endif //EX4_CLI_H
