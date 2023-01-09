//
// Created by kashann on 08/01/2023.
//

#ifndef EX4_CHOOSETHREE_H
#define EX4_CHOOSETHREE_H

#endif //EX4_CHOOSETHREE_H

#include "Command.h"
#include "knn.h"

class chooseThree : public Command {
public :

    chooseThree(CLI *data, std::string description, DefaultIO *dio);

    void execute();

    string findPredict(KNN knn, vector<float> vec);

    static bool sortbysec(const pair<string, int> &a, const pair<string, int> &b);
};
