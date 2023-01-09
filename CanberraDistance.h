//
// Created by kashann on 16/11/2022.
//

#ifndef EX1PART2_CANBERRADISTANCE_H
#define EX1PART2_CANBERRADISTANCE_H

#endif //EX1PART2_CANBERRADISTANCE_H
#include "../apEx2/Distance.h"

class CanberraDistance : public Distance {
public:
    float computeDistance(vector<float> vector1 , vector<float> vector2) override;
};