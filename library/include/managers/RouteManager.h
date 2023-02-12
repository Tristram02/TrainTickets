#ifndef KOLEJE_BILETY_ROUTEMANAGER_H
#define KOLEJE_BILETY_ROUTEMANAGER_H
#include "typedefs.h"
#include <vector>
#include "model/Route.h"
#include "model/Repository.h"
#include "exceptions/ParameterExceptions.h"

class RouteManager {
private:
	RouteRepositoryPtr routeRepository;
public:
	RouteManager(const RouteRepositoryPtr& routeRepository);
	virtual ~RouteManager();

	RoutePtr registerRoute(string routeID, string origin, string destination, double kilometers, pt::ptime departureTime, pt::ptime arrivalTime);

	void unregisterRoute(RoutePtr route);

	RoutePtr getRoute(string routeID);
	vector<RoutePtr> getAllRoutes();
};



#endif
