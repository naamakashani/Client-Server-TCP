//
// Created by kashann on 09/01/2023.
//

#include "chooseFive.h"

chooseFive::chooseFive(Data *data, std::string description, DefaultIO *dio) : Command(data, description, dio) {

}

void chooseFive::execute() {

    if (m_data->m_fileTrain.empty() || m_data->m_fileTest.empty()) {
        m_dio->write("Please upload data");

    } else {
        if (m_data->m_labels.empty()) {
            m_dio->write("Please classify the data");

        } else {

            std::string sendString = "";
            for (int i = 0; i < m_data->m_labels.size(); i++) {
                sendString += std::to_string(i + 1) + " " + m_data->m_labels[i] + "\n";

            }
            m_data->m_labelsString = sendString;
            sendString += "*EOF";
            m_dio->write(sendString);
        }
    }
}
