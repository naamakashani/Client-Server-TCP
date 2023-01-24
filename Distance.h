//
// Created by kashann on 16/11/2022.
//
#include <vector>
#include <iostream>

#ifndef EX1PART2_DISTANCE_H
#define EX1PART2_DISTANCE_H

using namespace std;
class Distance{
public:
    virtual float computeDistance(vector<float> vector1 , vector<float> vector2) = 0;

};

#endif //EX1PART2_DISTANCE_H
