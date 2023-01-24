//
// Created by kashann on 16/11/2022.
//

#include "CanberraDistance.h"

using namespace std;

#include<iostream>
#include<math.h>
#include <bits/stdc++.h>

float CanberraDistance::computeDistance(vector<float> vector1, vector<float> vector2) {
    float sum = 0;
    int i;
    vector<float> distance;
    for (i = 0; i < std::min(vector1.size(), vector2.size()); i++) {
        float x = abs(vector1[i] - vector2[i]);
        float y = abs(vector1[i]) + abs(vector2[i]);
        sum = sum + (x / y);

    }
    //if one vector is longer than the other
    if (i < vector1.size() - 1) {
        for (int j = i; j < vector1.size(); j++) {
            sum = sum + 1;
        }
    }
    if (i < vector2.size() - 1) {
        for (int j = i; j < vector2.size(); j++) {
            sum = sum + 1;
        }
    }
    return (sum);
}

