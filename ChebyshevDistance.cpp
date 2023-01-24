//
// Created by kashann on 16/11/2022.
//

#include "ChebyshevDistance.h"

using namespace std;

#include<iostream>
#include<math.h>
#include <bits/stdc++.h>

float ChebyshevDistance::computeDistance(vector<float> vector1, vector<float> vector2) {
    float sum = 0;
    int i;
    vector<float> distance;
    for (i = 0; i < std::min(vector1.size(), vector2.size()); i++) {
        distance.push_back(abs(vector1[i] - vector2[i]));
    }
    //if one vector is longer than the other
    if (i < vector1.size() - 1) {
        for (int j = i; j < vector1.size(); j++) {
            distance.push_back(vector1[j]);
        }
    }
    if (i < vector2.size() - 1) {
        for (int j = i; j < vector2.size(); j++) {
            distance.push_back(vector2[j]);
        }
    }
    return (*max_element(distance.begin(), distance.end()));
}


