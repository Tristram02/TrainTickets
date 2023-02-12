//
// Created by student on 30.05.2022.
//
#include <iomanip>

#include "model/Route.h"
#include <string>
Route::Route(string routeID, string origin, string destination, double kilometers, pt::ptime departureTime, pt::ptime arrivalTime)
: routeID(routeID), origin(origin), destination(destination), kilometers(kilometers), departureTime(departureTime), arrivalTime(arrivalTime)
{
    if(routeID == "") // routeID nie moze byc puste
    {
        throw ParameterExceptions("Error! Route ID can not be empty!");
    }
    if(origin == "") // origin nie moze byc puste
    {
        throw ParameterExceptions("Error! Origin can not be empty!");
    }
    if(destination == "") // origin nie moze byc puste
    {
        throw ParameterExceptions("Error! Destination can not be empty!");
    }
    if(kilometers <= 0) // kilometry musza byc dodatnie
    {
        throw ParameterExceptions("Error! Number of kilometers can not be smaller or equal to 0!");
    }
    if(departureTime == pt::not_a_date_time ) // jesli czas odjazdu nie jest data
    {
        throw ParameterExceptions("Error! Departure time must be a valid date");
    }
    if(arrivalTime == pt::not_a_date_time ) // jesli czas przyjazdu nie jest data
    {
        throw ParameterExceptions("Error! Arrival time must be a valid date");
    }
}
Route::~Route()
{

};
const string &Route::getRouteID() const
{
    return routeID;
}
const string &Route::getOrigin() const
{
    return origin;
}
const string &Route::getDestination() const
{
    return destination;
}
const double &Route::getKilometers() const
{
    return kilometers;
}
const pt::ptime &Route::getDepartureTime() const
{
    return departureTime;
}
const pt::ptime &Route::getArrivalTime() const
{
    return arrivalTime;
}
pt::time_duration Route::getTravelTime()
{
    pt::time_period travelTime(departureTime, arrivalTime);
    return travelTime.length();
}
// inne metody
string Route::getInfo()
{
    stringstream ss;

    ss << "Route info:\n----------------------\nRoute ID: ";
    ss <<  routeID;
    ss <<  "\nOrigin: ";
    ss <<  origin;
    ss << "\nDeparture time: ";
    ss << departureTime;
    ss << "\nDestination: " ;
    ss << destination;
    ss << "\nArrival time: ";
    ss << arrivalTime;
    ss << "\nTravel time: ";
    ss << getTravelTime();
    ss << "\nRoute length: ";
    ss << fixed << setprecision(1) << kilometers;
    ss << "\n-----------------\n";
    return ss.str();
}