//
// Created by student on 29.05.2022.
//

#ifndef KOLEJE_BILETY_DISABLED_H
#define KOLEJE_BILETY_DISABLED_H


#include "PassengerType.h"

class Disabled : public PassengerType {
public:
    double getPassengerDiscount() override;
    string getPassengerTypeInfo() override;
};


#endif //KOLEJE_BILETY_DISABLED_H
