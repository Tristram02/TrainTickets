#include "managers/TicketManager.h"

TicketManager::TicketManager(const TicketRepositoryPtr &currentTickets, const TicketRepositoryPtr &archiveTickets) : currentTickets(currentTickets), archiveTickets(archiveTickets){}

TicketManager::~TicketManager() = default;

TicketPtr TicketManager::buyTicket(const PassengerPtr& passenger, const TrainPtr& train, const RoutePtr& route, const double &price)
{
    TicketPredicate f = [train, route, this](const TicketPtr& ticket) -> bool {
        int found = 0;
        for(auto x: this->currentTickets->findAllObjects())
        {
            if(x->getTrain() == train)
                found++;
        }
        return found < train->getCapacity();// && pt::second_clock::local_time() < route->getDepartureTime() - pt::minutes(2);
    };

    if(!f)
    {
        return nullptr;
    }
    else
    {
        boost::uuids::random_generator id;
        TicketPtr newTicket = make_shared<Ticket>(id(), passenger, route, train, pt::not_a_date_time, price);
        currentTickets->addObject(newTicket);
        return newTicket;
    }
}

void TicketManager::ticketExpire(const TicketPtr& ticket)
{
    if(ticket->isExpired())
    {
        archiveTickets->addObject(ticket);
        ticket->setUsed(true);
        currentTickets->removeObject(ticket);
    }
}

//zwraca wszystkie aktywne kupione przez pasażera bilety
vector <TicketPtr> TicketManager::findPassengerTickets(const PassengerPtr& passenger)
{
    vector<TicketPtr> found;
    for(auto x: currentTickets->findAllObjects())
    {
        if(x->getPassenger() == passenger)
            found.push_back(x);
    }
    return found;
}

//zwraca wszystkie zarchiwizowane bilety pasazera
vector<TicketPtr> TicketManager::findAllBoughtTickets(const PassengerPtr& passenger)
{
    vector<TicketPtr> found;
    for(auto x: archiveTickets->findAllObjects())
    {
        if(x->getPassenger() == passenger)
            found.push_back(x);
    }
    return found;
}

void TicketManager::returnTicket(const TicketPtr& ticket)
{
//    if(ticket->getRoute()->getDepartureTime() > pt::second_clock::local_time())
//    {
//        archiveTickets->addObject(ticket);
//        ticket->setUsed(false);
//        ticket->setReturned(true);
//        currentTickets->removeObject(ticket);
//    }
}