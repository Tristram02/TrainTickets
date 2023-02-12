#include "model/LKA.h"


LKA::LKA(const string& trainNumber, const double& basePrice, const int& capacity) : Train(trainNumber,basePrice,capacity)
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

LKA::~LKA() =default;

const string &LKA::getTrainNumber()
{
    return Train::getTrainNumber();
}

const double &LKA::getBasePrice()
{
    return Train::getBasePrice();
}

const int &LKA::getCapacity()
{
    return Train::getCapacity();
}

string LKA::getInfo()
{
    return "LKA: " + Train::getInfo();
}