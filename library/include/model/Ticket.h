//
// Created by student on 30.05.2022.
//

#ifndef KOLEJE_BILETY_TICKET_H
#define KOLEJE_BILETY_TICKET_H

#include "typedefs.h"
#include <string>
#include <boost/date_time.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp>

using namespace std;
namespace pt = boost::posix_time;

class Ticket {
private:
    boost::uuids::uuid ticketID;
    pt::ptime expireDate;
    double price;
    bool returned; // czy bilet jest zwrocony
    bool used; // czy bilet jest uzyty
    // klasy
    PassengerPtr passenger;
    RoutePtr route;
    TrainPtr train;
public:
    // konstruktor, destruktor
    Ticket(boost::uuids::uuid ticketID, PassengerPtr passenger, RoutePtr route, TrainPtr train, pt::ptime expireDate, double price);
    ~Ticket();
    // settery
    void setUsed(const bool &use);
    void setReturned(const bool& ret);// ret = returned

    // gettery
    const boost::uuids::uuid &getTicketID() const;
    const pt::ptime &getExpireDate() const;
    const double &getPrice() const;
    const bool& isReturned() const;
    const bool& isUsed() const;
    const TrainPtr& getTrain() const;
    const PassengerPtr& getPassenger() const;
    const RoutePtr& getRoute() const;

    // inne metody
    string getInfo();
    bool isExpired();
};


#endif //KOLEJE_BILETY_TICKET_H
