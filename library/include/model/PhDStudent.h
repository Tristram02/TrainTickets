//
// Created by student on 29.05.2022.
//

#ifndef KOLEJE_BILETY_PHDSTUDENT_H
#define KOLEJE_BILETY_PHDSTUDENT_H


#include "PassengerType.h"

class PhDStudent : public PassengerType {
public:
    double getPassengerDiscount();
    string getPassengerTypeInfo() override;
};


#endif //KOLEJE_BILETY_PHDSTUDENT_H
