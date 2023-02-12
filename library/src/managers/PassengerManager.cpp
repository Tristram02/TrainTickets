#include "../../include/managers/PassengerManager.h"



PassengerManager::PassengerManager(const PassengerRepositoryPtr& passengerRepository) : passengerRepository(passengerRepository)
{
    if(passengerRepository == nullptr)
    {
        throw ParameterExceptions("Error! You can not create Manager without Repository");
    }
}

PassengerManager::~PassengerManager() = default;

PassengerPtr PassengerManager::registerPassenger(const string &name, const string &lastName, const string& passengerID, const PassengerTypePtr& passengerType)
{
    PassengerPredicate f = [passengerID](const PassengerPtr& passenger) -> bool{return passenger->getPassengerID() == passengerID;};
    if(!passengerRepository->findObject(f).empty())
    {
        return passengerRepository->findObject(f)[0];
    }
    else
    {
        PassengerPtr newPassenger = make_shared<Passenger>(name,lastName,passengerID,passengerType);
        passengerRepository->addObject(newPassenger);
        return newPassenger;
    }
}

void PassengerManager::unregisterPassenger(PassengerPtr passenger)
{
    if(passenger == nullptr)
    {
        throw ParameterExceptions("Error! Invalid PassengerPtr!");
    }
    passenger->setArchived(true);
}

PassengerPtr PassengerManager::getPassenger(const string &passengerID)
{
    for(auto x : passengerRepository->findAllObjects())
    {
        if(x->getPassengerID() == passengerID)
            return x;
    }
}

vector<PassengerPtr> PassengerManager::getAllPassengers()
{
    return passengerRepository->findAllObjects();
}