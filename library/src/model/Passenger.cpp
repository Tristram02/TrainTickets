//
// Created by student on 23.05.2022.
//

#include "../../include/model/Passenger.h"

// konstruktor i destruktor
Passenger::Passenger(string name, string lastName, string passengerID, PassengerTypePtr passengerType) : name(name), lastName(lastName), passengerID(passengerID), passengerType(passengerType)
{
    archive = false; // przy utworzeniu ma byc nie archiwizowany
    if(name == "")
    {
        throw ParameterExceptions("Error! Passenger name can not be empty!");
    }
    if(lastName == "")
    {
        throw ParameterExceptions("Error! Passenger lastname can not be empty!");
    }
    if(passengerID == "")
    {
        throw ParameterExceptions("Error! Passenger ID can not be empty!");
    }
    if(passengerType == nullptr) // nie wiem czy to ma byc
    {
        throw ParameterExceptions("Invalid passenger type");
    }
}
Passenger::~Passenger()
{

}

// settery
void Passenger::setName(const string &newName)
{
    if(newName.empty())
        return;
    name = newName;
}
void Passenger::setLastName(const string &newLastName)
{
    if(newLastName.empty())
        return;
    lastName = newLastName;
}
void Passenger::setPassengerType(PassengerTypePtr newPassengerType)
{
    if (newPassengerType == nullptr) return;
    passengerType = newPassengerType;
}
void Passenger::setArchived(const bool newArchived) // ustawia pasazera jako zarchiwizowanego lub nie
{
    archive = newArchived;

}
// gettery
const string &Passenger::getName() const
{
    return name;
}
const string &Passenger::getLastName() const
{
    return lastName;
}
const string &Passenger::getPassengerID() const
{
    return passengerID;
}
const bool &Passenger::isArchive() const
{
    return archive;
}
PassengerTypePtr Passenger::getPassengerType() {
    return passengerType;
};

// inne metody
string Passenger::getInfo()
{
    return "Passenger info: \nName: " + name + "\nLast name: " + lastName + "\nID: " + passengerID + "\nPassenger type: " + passengerType->getPassengerTypeInfo(); // narazie bez PassengerType
}
double Passenger::getPassengerDiscount(PassengerTypePtr passengerType)
{
    return passengerType->getPassengerDiscount();
}
