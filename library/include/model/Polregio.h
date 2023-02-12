#ifndef KOLEJE_BILETY_POLREGIO_H
#define KOLEJE_BILETY_POLREGIO_H
#include "Train.h"

class Polregio : public Train {
public:
    Polregio(const string& trainNumber, const double& basePrice, const int& capacity);
    ~Polregio() override;
    //getters
    const string& getTrainNumber() override;
    const double& getBasePrice() override;
    const int& getCapacity() override;
    //methods
    string getInfo() override;
};


#endif //KOLEJE_BILETY_POLREGIO_H
