//
// Created by student on 26.05.2022.
//

#ifndef KOLEJE_BILETY_PASSENGERTYPE_H
#define KOLEJE_BILETY_PASSENGERTYPE_H

using namespace std;

#include <string>

class PassengerType {
public:
    PassengerType();
    virtual ~PassengerType();
    virtual double getPassengerDiscount () = 0; // metoda dziedziczona
    virtual string getPassengerTypeInfo () = 0; // metoda dziedziczona
};


#endif //KOLEJE_BILETY_PASSENGERTYPE_H
