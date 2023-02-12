#ifndef KOLEJE_BILETY_TYPEDEFS_H
#define KOLEJE_BILETY_TYPEDEFS_H
#include <memory>
#include <functional>

using namespace std;

//Zapowiedzi klas
template <class T>
class Repository;

class Passenger;
class Train;
class Polregio;
class LKA;
class Intercity;
class Disabled;
class Disciple;
class Normal;
class PassengerType;
class PhDStudent;
class Senior;
class Student;
class Route;
class Ticket;

class PassengerManager;
class Ticket;
class TrainManager;
class TicketManager;

//model
typedef shared_ptr<Passenger> PassengerPtr;
typedef shared_ptr<Train> TrainPtr;
typedef shared_ptr<Polregio> PolregioPtr;
typedef shared_ptr<Intercity> IntercityPtr;
typedef shared_ptr<LKA> LKAPtr;
typedef shared_ptr<Disabled> DisabledPtr;
typedef shared_ptr<Disciple> DisciplePtr;
typedef shared_ptr<Normal> NormalPtr;
typedef shared_ptr<PassengerType> PassengerTypePtr;
typedef shared_ptr<PhDStudent> PhDStudentPtr;
typedef shared_ptr<Senior> SeniorPtr;
typedef shared_ptr<Student> StudentPtr;
typedef shared_ptr<Route> RoutePtr;
typedef shared_ptr<Ticket> TicketPtr;


//managers
typedef shared_ptr<PassengerManager> PassengerManagerPtr;
typedef shared_ptr<TrainManager> TrainManagerPtr;
typedef shared_ptr<TicketManager> TicketManagerPtr;

//Repozytorium
typedef shared_ptr<Repository<PassengerPtr>> PassengerRepositoryPtr;
typedef shared_ptr<Repository<TrainPtr>> TrainRepositoryPtr;
typedef shared_ptr<Repository<TicketPtr>> TicketRepositoryPtr;
//predykaty
typedef function<bool(PassengerPtr)> PassengerPredicate;
typedef function<bool(TrainPtr)> TrainPredicate;
typedef function<bool(TicketPtr)> TicketPredicate;
#endif //KOLEJE_BILETY_TYPEDEFS_H
