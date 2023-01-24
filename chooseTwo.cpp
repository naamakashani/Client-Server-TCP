//
// Created by kashann on 09/01/2023.
//

#include <sstream>
#include "chooseTwo.h"
#include <unistd.h>

chooseTwo::chooseTwo(Data *data, std::string description, DefaultIO *dio) : Command(data, description, dio) {

}

bool chooseTwo::validK(std::string k) {
    try {
        int num = std::stoi(k);
        if (num > 0) {
            return true;
        } else {
            return false;
        }

    }
    catch (const std::invalid_argument &) {
        return false;
    }
}

bool chooseTwo::validMetric(std::string dis) {
    if (dis == "AUC" || dis == "MAN" || dis == "CHB" || dis == "CAN" || dis == "MIN") {
        return true;
    } else {
        return false;
    }
}

void chooseTwo::execute() {
    std::string sendString = "The current parameters are: K = " + std::to_string(m_data->m_k) + ", distance metric = " +
                             m_data->m_metric;
    m_dio->write(sendString);
    std::string answer = m_dio->read();
    sleep(1);
    if (!answer.empty() && !(answer == "enter")) {
        //check that the answer has exactly 2 words

        int count = 0;
        std::istringstream iss(answer);
        std::string k, dis;
        while (std::getline(iss, k, ' ')) {
            count++;
            std::getline(iss, dis, ' ');
            count++;
        }
        if (count == 2) {
            if (validMetric(dis) && validK(k)) {
                int num = std::stoi(k);
                m_data->m_k = num;
                m_data->m_metric = dis;
                m_dio->write("null");
            } else {
                if (!validMetric(dis)) {
                    m_dio->write("invalid value for metric");
                }
                if (!validK(k)) {
                    m_dio->write("invalid value for K");
                }

            }
        } else {
            m_dio->write("invalid input");
        }
    }
    m_dio->write("null");
}