
#include <iostream>
#include<stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <vector>
#include "MinkowskiDistance.h"
#include "EuclideanDistance.h"
#include "ManhattanDistance.h"
#include "CanberraDistance.h"
#include "ChebyshevDistance.h"

class KNN {
public:
    int k;
    string filePath;
    const char *metric;
    vector<vector<float>> content;
    vector<vector<float>> contentTest;
    vector<string> labels;
    vector<pair<string, int>> distanceData;

    KNN(int num, string file, const char *met) {

        k = num;
        filePath = file;
        metric = met;
    }

    /***
     * set the metric
     * @param newMetric
     */

    void setMetric(const char *newMetric);

/***
 * find the distance metric
 * @return the metric
 */
    Distance *findMetric();

    /***
* load data from csv file into vectors
* @param content vector data insert to
* @param labels vectors labels insert
*/

/***
 *
 * @param str
 * @return true if the string contains only digits
 */
    bool isNumber(string str);

    /***
     * save the distance of the vector from the data
     * @param vec is the vector input
     */
    void saveDistance(vector<float> vec);

    /***
     *
     * @param sortVector the sorted vector
     * @return the predicted element of the k nearest neighbors.
     */

    string predict(vector<pair<string, int>> sortVector);


    vector<vector<float>> saveTestData(string fileTest);

    void saveDataTrain(string fileTrain);
    void saveData(std:: string filePath);

    void saveTestPath(string fileTest);

    void saveDataPath(string filePath);
};


