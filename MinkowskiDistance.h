


//
// Created by kashann on 16/11/2022.
//

#ifndef EX1PART2_MINKOWSKIDISTANCE_H
#define EX1PART2_MINKOWSKIDISTANCE_H

#endif //EX1PART2_MINKOWSKIDISTANCE_H

#include "Distance.h"

using namespace std;

#include<iostream>
#include<math.h>
#include <bits/stdc++.h>

class MinkowskiDistance : public Distance {
public:
    float computeDistance(vector<float> vector1, vector<float> vector2) override;
};