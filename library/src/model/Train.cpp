#include "model/Train.h"

Train::Train(const string& trainNumber, const double& basePrice, const int& capacity) : trainNumber(trainNumber), basePrice(basePrice), capacity(capacity)
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

Train::~Train() = default;

const string& Train::getTrainNumber()
{
    return trainNumber;
}

const double& Train::getBasePrice()
{
    return basePrice;
}

const int& Train::getCapacity()
{
    return capacity;
}

string Train::getInfo()
{
    return trainNumber + ", capacity: " + to_string(capacity) + ", cost by kilometer: " + to_string(basePrice);
}