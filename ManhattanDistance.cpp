//
// Created by kashann on 16/11/2022.
//

using namespace std;

#include<iostream>
#include<cmath>
#include "ManhattanDistance.h"

float ManhattanDistance::computeDistance(vector<float> vector1, vector<float> vector2) {
    float sum = 0,x;
    int i;
    for (i = 0; i < std::min(vector1.size(), vector2.size()); i++) {
        x = (vector1[i] - vector2[i]);
        sum = sum + abs(x);
    }
    //if one vector is longer than the other
    if (i < vector1.size() - 1) {
        for (int j = i; j < vector1.size(); j++) {
            sum = sum + vector1[j];
        }
    }
    if (i < vector2.size() - 1) {
        for (int j = i; j < vector2.size(); j++) {
            sum = sum + vector2[j];
        }
    }
    return (sum);

}


