//
// Created by student on 23.05.2022.
//

#ifndef KOLEJE_BILETY_PASSENGER_H
#define KOLEJE_BILETY_PASSENGER_H

#include <string>
#include "PassengerType.h"
#include "typedefs.h"
#include "exceptions/ParameterExceptions.h"
using namespace std;

class Passenger {
private: // atrybuty
    string name;
    string lastName;
    string passengerID;
    bool archive; // status zarchiwizowania
    PassengerTypePtr passengerType; // wskaznik na klase passengertype
public:
        // konstruktor i destruktor
    Passenger(string name, string lastName, string passengerID, PassengerTypePtr passengerType);
    ~Passenger();

        // settery
    void setName(const string &newName);
    void setLastName(const string &newLastName);
    void setPassengerType(PassengerTypePtr newPassengerType);
    void setArchived(const bool archived); // ustawia pasazera jako zarchiwizowanego lub nie

        // gettery
    const string &getName() const;
    const string &getLastName() const;
    const string &getPassengerID() const;
    const bool &isArchive() const;
    PassengerTypePtr getPassengerType();
        // inne metody
    string getInfo();
    double getPassengerDiscount(PassengerTypePtr passengerType);
};

#endif //KOLEJE_BILETY_PASSENGER_H
