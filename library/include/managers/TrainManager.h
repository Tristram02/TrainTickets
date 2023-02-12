//
// Created by student on 30.05.2022.
//

#ifndef KOLEJE_BILETY_TRAINMANAGER_H
#define KOLEJE_BILETY_TRAINMANAGER_H
#include "typedefs.h"
#include <vector>
#include "exceptions/ParameterExceptions.h"
#include "model/Train.h"
#include "model/Polregio.h"
#include "model/Intercity.h"
#include "model/LKA.h"
#include "model/Repository.h"

class TrainManager {
private:
    TrainRepositoryPtr trainRepository;
public:
    //constructor, destructor
    TrainManager(const TrainRepositoryPtr& trainRepository);
    virtual ~TrainManager();
    //methods
    TrainPtr registerPolregio(const string& trainNumber, const double& basePrice, const int& capacity);
    TrainPtr registerIntercity(const string& trainNumber, const double& basePrice, const int& capacity);
    TrainPtr registerLKA(const string& trainNumber, const double& basePrice, const int& capacity);
    TrainPtr getTrain(const string& trainNumber);
    vector<TrainPtr> getAllTrains();
};


#endif //KOLEJE_BILETY_TRAINMANAGER_H
