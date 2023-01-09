
#include "knn.h"


bool KNN::isNumber(string str) {
    for (int i = 0; i < str.size(); i++)
        if (str.find_first_not_of("0123456789.") == std::string::npos)
            return true;
    return false;
}

vector<vector<float>> KNN::saveTestData(string fileTest) {
    vector<vector<float>> contentTest;
    vector<float> row;
    string line, word;
    std::istringstream tokenStream(fileTest);
    while (std::getline(tokenStream, line, '\n')) {
        row.clear();
        stringstream str(line);
        while (getline(str, word, ',')) {
            double num = std::stod(word);
            row.push_back(num);
        }
        contentTest.push_back(row);
    }
    return contentTest;
}

void KNN::saveDataTrain(string fileTrain) {
    vector<float> row;
    string line, word;
    std::istringstream tokenStream(fileTrain);
    while (std::getline(tokenStream, line, '\n')) {
        row.clear();
        stringstream str(line);
        bool read_label = 0;
        while (getline(str, word, ',')) {
            try {
                double num = std::stod(word);
                row.push_back(num);
            }
            catch (std::invalid_argument &) {
                if (read_label != 0)
                    throw "csv file is invalid, two labels in a row";
                labels.push_back(word);
                read_label = 1;
            }

        }
        content.push_back(row);
    }
}


void KNN::setMetric(const char *newMetric) {
    metric = newMetric;
}

Distance *KNN::findMetric() {
    Distance *distanceMetric;
    const char *str = "AUC";
    if (strcmp(metric, str) == 0) {
        EuclideanDistance *euclidean = new EuclideanDistance();
        return euclidean;

    }
    const char *str2 = "MAN";
    if (strcmp(metric, str2) == 0) {
        ManhattanDistance *manhattan = new ManhattanDistance();
        return manhattan;
    }
    const char *str3 = "CHB";
    if (strcmp(metric, str3) == 0) {
        ChebyshevDistance *chebyshev = new ChebyshevDistance();
        return chebyshev;

    }
    const char *str4 = "CAN";
    if (strcmp(metric, str4) == 0) {
        CanberraDistance *canberra = new CanberraDistance;
        return canberra;

    }
    const char *str5 = "MIN";
    if (strcmp(metric, str5) == 0) {
        MinkowskiDistance *minkowski = new MinkowskiDistance();
        return minkowski;

    }
    return distanceMetric;
}

void KNN::saveDistance(vector<float> vec) {

    float value;
    for (int i = 0; i <= content.size() - 1; i++) {
        value = findMetric()->computeDistance(content[i], vec);
        distanceData.push_back(make_pair(labels[i], value));
    }

}


string KNN::predict(vector<pair<string, int>> sortVector) {

    map<string, int> countClasses;
    for (int i = 0; i < labels.size(); i++) {
        countClasses[labels[i]] = 0;

    }
    int counter = 0;
    while (counter < k) {
        countClasses[sortVector[k].first]++;
        counter++;
    }
    auto x = std::max_element(countClasses.begin(), countClasses.end(),
                              [](const pair<string, int> &p1, const pair<string, int> &p2) {
                                  return p1.second < p2.second;
                              });
    return x->first;


}














