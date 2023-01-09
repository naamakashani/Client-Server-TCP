//
// Created by kashann on 16/11/2022.
//

#ifndef EX1PART2_MANHATTAN_DISTANCE_H
#define EX1PART2_MANHATTAN_DISTANCE_H
#endif //EX1PART2_MANHATTAN_DISTANCE_H


#include "Distance.h"
class ManhattanDistance : public Distance {
public:
    float computeDistance(vector<float> vector1 , vector<float> vector2) override;
};
