//
// Created by kashann on 09/01/2023.
//
//
// Created by kashann on 08/01/2023.
//

#include <sstream>
#include "chooseTwo.h"
chooseTwo:: chooseTwo(Data* data, std::string description, DefaultIO* dio) : Command(data, description , dio){

}
bool chooseTwo::validK(std::string k) {
    try {
        int num = std::stoi(k);
        return true;

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
    std::string sendString = "The current parameters are: K = " + std::to_string(m_data->m_k ) + ", distance metric = " + m_data->m_metric;
    m_dio->write(sendString);
    std::string answer = m_dio->read();
    if (!answer.empty()) {
        std::istringstream iss(answer);
        std::string k, dis;
        std::getline(iss, k, ' ');
        std::getline(iss, dis, ' ');
        if (validMetric(dis) && validK(k)) {
            int num = std::stoi(k);
            m_data->m_k = num;
            m_data->m_metric = dis;


        } else {
            if (!validMetric(dis)) {
                m_dio->write("invalid value for metric");
            }
            if (!validK(k)) {
                m_dio->write("invalid value for K");
            }

        }


    }


}