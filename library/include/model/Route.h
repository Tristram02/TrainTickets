//
// Created by student on 30.05.2022.
//

#ifndef KOLEJE_BILETY_ROUTE_H
#define KOLEJE_BILETY_ROUTE_H

#include <string>
#include "boost/date_time.hpp"
#include "exceptions/ParameterExceptions.h"
namespace pt = boost::posix_time;
namespace gr = boost::gregorian;
using namespace std;

class Route {
private:
    string routeID;
    string origin;
    string destination;
    double kilometers;
    pt::ptime departureTime; // data
    pt::ptime arrivalTime; // data
public:
    // konstuktor, destruktor
    Route(string routeID, string origin, string destination, double kilometers, pt::ptime departureTime, pt::ptime arrivalTime);
    ~Route();
    // setterow nie ma bo atrybuty trasy sa teoretycznie niezmienialne
    // gettery
    const string &getRouteID() const;
    const string &getOrigin() const;
    const string &getDestination() const;
    const double &getKilometers() const;
    const pt::ptime &getDepartureTime() const;
    const pt::ptime &getArrivalTime() const;
    // inne metody
    pt::time_duration getTravelTime();
    string getInfo();
};


#endif //KOLEJE_BILETY_ROUTE_H
