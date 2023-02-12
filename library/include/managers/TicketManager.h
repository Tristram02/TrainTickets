#ifndef KOLEJE_BILETY_TICKETMANAGER_H
#define KOLEJE_BILETY_TICKETMANAGER_H
#include "model/Repository.h"
#include "model/Ticket.h"
#include "typedefs.h"
#include "model/Train.h"

class TicketManager {
private:
    TicketRepositoryPtr currentTickets;
    TicketRepositoryPtr archiveTickets;
public:
    TicketManager(const TicketRepositoryPtr& currentTickets, const TicketRepositoryPtr& archiveTickets);
    virtual ~TicketManager();
    //methods
    TicketPtr buyTicket(const PassengerPtr& passenger, const TrainPtr& train, const RoutePtr& route, const double& price);//kupno nowego biletu
    void ticketExpire(const TicketPtr& ticket);//metoda sprawdza czy bilet stracil waznosc
    vector<TicketPtr> findPassengerTickets(const PassengerPtr& passenger);//zwraca wszystkie aktywne kupione przez pasażera bilety
    vector<TicketPtr> findAllBoughtTickets(const PassengerPtr& passenger);//zwraca wszystkie zarchiwizowane bilety pasazera
    void returnTicket(const TicketPtr& ticket);//metoda zwracajaca kupiony bilet

};


#endif //KOLEJE_BILETY_TICKETMANAGER_H
