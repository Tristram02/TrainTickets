//
// Created by student on 29.05.2022.
//

#ifndef KOLEJE_BILETY_SENIOR_H
#define KOLEJE_BILETY_SENIOR_H


#include "PassengerType.h"

class Senior : public PassengerType {
public:
    double getPassengerDiscount();
    string getPassengerTypeInfo() override;
};


#endif //KOLEJE_BILETY_SENIOR_H
