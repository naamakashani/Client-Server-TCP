//
// Created by kashann on 16/11/2022.
//
#include<iostream>
#include<math.h>
#include "EuclideanDistance.h"

using namespace std;

float EuclideanDistance::computeDistance(vector<float> vector1, vector<float> vector2){
    float sum = 0, x=0;
    int i;
    for (i = 0; i < std::min(vector1.size(), vector2.size()); i++) {
        x = (vector1[i] - vector2[i]);
        sum = sum + pow(x, 2);
    }
    //if one vector is longer than the other
    if (i < vector1.size() - 1) {
        for (int j = i; j < vector1.size(); j++) {
            sum = sum + pow(vector1[j], 2);
        }
    }
    if (i < vector2.size() - 1) {
        for (int j = i; j < vector2.size(); j++) {
            sum = sum + pow(vector2[j], 2);
        }
    }
    return sqrt(sum);

}


