//
// Created by kashann on 08/01/2023.
//

#include "chooseThree.h"


chooseThree::chooseThree(CLI *data, std::string description, DefaultIO *dio) : Command(data, description, dio) {};

bool chooseThree::sortbysec(const pair<string, int> &a,
                            const pair<string, int> &b) {
    return (a.second > b.second);


}

string chooseThree::findPredict(KNN knn, vector<float> vec) {
    knn.saveDistance(vec);
    sort(knn.distanceData.begin(), knn.distanceData.end(), sortbysec);
    string predictClass = knn.predict(knn.distanceData);
    return predictClass;

}


void chooseThree::execute() {
    vector<string> labels;
    std::string str;
    ///convert string to const char *
    std::string dis = m_data->m_metric;
    const char *met = dis.c_str();
    KNN knn = KNN(m_data->m_k, m_data->m_fileTrain, met);
    knn.saveDataPath(m_data->m_fileTrain);
    if (!knn.content.empty()) {
        knn.saveTestPath(m_data->m_fileTest);
        if (!knn.contentTest.empty()) {
            for (const auto &innerVector: knn.contentTest) {
                str = findPredict(knn, innerVector);
                labels.push_back(str);

            }
            m_dio->write("data classifying complete");
            m_data->m_labels = labels;


        } else {
            m_dio->write("please upload data");
        }

    } else {
        m_dio->write("please upload data");
    }
}