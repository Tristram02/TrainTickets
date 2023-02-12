#include "model/Intercity.h"


Intercity::Intercity(const string& trainNumber, const double& basePrice, const int& capacity) : Train(trainNumber,basePrice,capacity)
{
    if(trainNumber == "")//Identyfikator pociagu nie moze byc pusty
    {
        throw ParameterExceptions("Error! Train number can not be empty!");
    }
    if(basePrice <= 0)//cena nie moze byc mniejsza lub rowna 0
    {
        throw ParameterExceptions("Error! Base price can not be smaller or equal to 0!");
    }
    if(capacity <= 0)//Pojemnosc pociagu nie moze byc mniejsza lub rowna 0
    {
        throw ParameterExceptions("Error! Capacity can not be smaller or equal to 0!");
    }
}

Intercity::~Intercity() =default;

const string &Intercity::getTrainNumber()
{
    return Train::getTrainNumber();
}

const double &Intercity::getBasePrice()
{
    return Train::getBasePrice();
}

const int &Intercity::getCapacity()
{
    return Train::getCapacity();
}

string Intercity::getInfo()
{
    return "Intercity: " + Train::getInfo();
}