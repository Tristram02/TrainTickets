#ifndef KOLEJE_BILETY_LKA_H
#define KOLEJE_BILETY_LKA_H
#include "Train.h"

class LKA : public Train{
public:
    LKA(const string& trainNumber, const double& basePrice, const int& capacity);
    ~LKA() override;
    //getters
    const string& getTrainNumber() override;
    const double& getBasePrice() override;
    const int& getCapacity() override;
    //methods
    string getInfo() override;
};


#endif //KOLEJE_BILETY_LKA_H
