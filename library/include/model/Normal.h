//
// Created by student on 29.05.2022.
//

#ifndef KOLEJE_BILETY_NORMAL_H
#define KOLEJE_BILETY_NORMAL_H


#include "PassengerType.h"

class Normal : public PassengerType {
public:
    double getPassengerDiscount();
    string getPassengerTypeInfo() override;
};


#endif //KOLEJE_BILETY_NORMAL_H
