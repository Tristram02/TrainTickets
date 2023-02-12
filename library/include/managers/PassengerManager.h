
#ifndef KOLEJE_BILETY_PASSENGERMANAGER_H
#define KOLEJE_BILETY_PASSENGERMANAGER_H
#include "typedefs.h"
#include <vector>
#include "model/Passenger.h"
#include "model/Repository.h"
#include "exceptions/ParameterExceptions.h"

class PassengerManager {
private:
    PassengerRepositoryPtr passengerRepository;
public:
    PassengerManager(const PassengerRepositoryPtr& passengerRepository);
    virtual ~PassengerManager();

    PassengerPtr registerPassenger(const string& name, const string& lastName, const string& passengerID, const PassengerTypePtr& passengerType);
    void unregisterPassenger(PassengerPtr passenger);
    PassengerPtr getPassenger(const string& passengerID);
    vector<PassengerPtr> getAllPassengers();


};


#endif //KOLEJE_BILETY_PASSENGERMANAGER_H
