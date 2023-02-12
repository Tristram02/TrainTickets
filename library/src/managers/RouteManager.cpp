#include "model/RouteManager.h"

RouteManager::RouteManager(const RouteRepositoryPtr& routeReposiotry) : routeRepository(routeRepository)
{
	if (routeRepository == nullptr)
	{
		throw ParameterExceptions("Error! Manager can not be created without repository!");
	}
}