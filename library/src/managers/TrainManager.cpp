#include "managers/TrainManager.h"

TrainManager::TrainManager(const TrainRepositoryPtr &trainRepository) : trainRepository(trainRepository)
{
    if(trainRepository == nullptr)
    {
        throw ParameterExceptions("Error! You can not create manager without repository!");
    }
}

TrainManager::~TrainManager() = default;


TrainPtr TrainManager::registerPolregio(const string &trainNumber, const double &basePrice, const int &capacity)
{
    TrainPredicate f = [trainNumber](const TrainPtr& train) -> bool{return train->getTrainNumber() == trainNumber;};

    if(!trainRepository->findObject(f).empty())
    {
        return trainRepository->findObject(f)[0];
    }
    else
    {
        TrainPtr newTrain = make_shared<Polregio>(trainNumber, basePrice, capacity);
        trainRepository->addObject(newTrain);
        return newTrain;
    }
}

TrainPtr TrainManager::registerIntercity(const string &trainNumber, const double &basePrice, const int &capacity) {
    TrainPredicate f = [trainNumber](const TrainPtr& train) -> bool{return train->getTrainNumber() == trainNumber;};

    if(!trainRepository->findObject(f).empty())
    {
        return trainRepository->findObject(f)[0];
    }
    else
    {
        TrainPtr newTrain = make_shared<Intercity>(trainNumber, basePrice, capacity);
        trainRepository->addObject(newTrain);
        return newTrain;
    }
}

TrainPtr TrainManager::registerLKA(const string &trainNumber, const double &basePrice, const int &capacity)
{
    TrainPredicate f = [trainNumber](const TrainPtr& train) -> bool{return train->getTrainNumber() == trainNumber;};

    if(!trainRepository->findObject(f).empty())
    {
        return trainRepository->findObject(f)[0];
    }
    else
    {
        TrainPtr newTrain = make_shared<LKA>(trainNumber, basePrice, capacity);
        trainRepository->addObject(newTrain);
        return newTrain;
    }
}

TrainPtr TrainManager::getTrain(const string &trainNumber)
{
    for(auto x : trainRepository->findAllObjects())
    {
        if(x->getTrainNumber() == trainNumber)
            return x;
    }
    return nullptr;
}

vector<TrainPtr> TrainManager::getAllTrains()
{
    return trainRepository->findAllObjects();
}

