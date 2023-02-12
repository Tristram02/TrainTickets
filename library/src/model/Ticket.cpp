//
// Created by student on 30.05.2022.
//

#include "model/Ticket.h"

Ticket::Ticket(boost::uuids::uuid ticketID, PassengerPtr passenger, RoutePtr route, TrainPtr train, pt::ptime expireDate, double price) : ticketID(ticketID), passenger(passenger), route(route), train(train), expireDate(expireDate), price(price)
{
    returned = false;
    used = false; // domyslnie maja byc nie zwrocone i nie uzyte
}
Ticket::~Ticket()
{

}
// settery
void Ticket::setUsed(const bool &use)
{
    used = use;
}

void Ticket::setReturned(const bool& ret)
{
    returned = ret;
}

// gettery
const boost::uuids::uuid &Ticket::getTicketID() const
{
    return ticketID;
}
const pt::ptime &Ticket::getExpireDate() const
{
    return expireDate;
}
const double &Ticket::getPrice() const
{
    return price;
}
const bool& Ticket::isReturned() const
{
    return returned;
}
const bool& Ticket::isUsed() const
{
    return used;
}

const TrainPtr& Ticket::getTrain() const
{
    return train;
}

const PassengerPtr& Ticket::getPassenger() const
{
    return passenger;
}

const RoutePtr& Ticket::getRoute() const
{
    return route;
}

// inne metody
string Ticket::getInfo()
{
    stringstream ss;
    ss << "Ticket info:\n";
    ss << "Ticket ID: ";
    ss << boost::uuids::to_string(ticketID);
    ss << "\nExpire date: ";
    ss << expireDate;
    ss << "\nPrice: ";
    ss << fixed << setprecision(2) << price;
    ss << "\nReturned: ";
    if(returned) ss << "Yes"; else ss << "No";
    ss << "\nUsed: ";
    if(used) ss << "Yes"; else ss << "No";
    ss << "\n-----------------\n";
    return ss.str();
}
bool Ticket::isExpired()
{
    pt::ptime now = pt::second_clock::local_time();
    if(expireDate < now) return true;
    else return false;
}