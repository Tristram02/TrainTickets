//
// Created by student on 29.05.2022.
//

#ifndef KOLEJE_BILETY_INTERCITY_H
#define KOLEJE_BILETY_INTERCITY_H
#include "Train.h"

class Intercity : public Train{
public:
    Intercity(const string& trainNumber, const double& basePrice, const int& capacity);
    ~Intercity() override;
    //getters
    const string& getTrainNumber() override;
    const double& getBasePrice() override;
    const int& getCapacity() override;
    //methods
    string getInfo() override;
};


#endif //KOLEJE_BILETY_INTERCITY_H
