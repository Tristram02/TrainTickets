#ifndef KOLEJE_BILETY_TRAIN_H
#define KOLEJE_BILETY_TRAIN_H
#include <string>
#include "exceptions/ParameterExceptions.h"

using namespace std;

class Train {
private:
    string trainNumber;
    double basePrice;
    int capacity;
public:
    Train(const string& trainNumber, const double& basePrice, const int& capacity);
    virtual ~Train() = 0;

    //getters
    virtual const string& getTrainNumber();

    virtual const double& getBasePrice();

    virtual const int& getCapacity();
    //methods
    virtual string getInfo();
};


#endif //KOLEJE_BILETY_TRAIN_H
