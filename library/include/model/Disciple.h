//
// Created by student on 29.05.2022.
//

#ifndef KOLEJE_BILETY_DISCIPLE_H
#define KOLEJE_BILETY_DISCIPLE_H

#include "PassengerType.h"

class Disciple : public PassengerType {
public:
    double getPassengerDiscount();
    string getPassengerTypeInfo() override;
};


#endif //KOLEJE_BILETY_DISCIPLE_H
