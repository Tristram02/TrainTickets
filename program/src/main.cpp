#include <iostream>

using namespace std;

#include "typedefs.h"
#include "model/Passenger.h"
#include "model/Student.h"
#include "model/Ticket.h"
#include "model/Route.h"
#include "model/Polregio.h"
#include "model/Train.h"
#include "model/Disabled.h"
#include "model/Disciple.h"
#include "model/Normal.h"
#include "model/PhDStudent.h"
#include "model/Senior.h"
#include "model/Student.h"


int main()
{
    boost::uuids::uuid hehe;
    // time declarations
    pt::ptime time1=pt::ptime(gr::date(2022,5,31),pt::hours(22)+pt::minutes(10));
    pt::ptime time2=pt::ptime(gr::date(2022,6,1),pt::hours(3)+pt::minutes(33));
    pt::ptime time3=pt::ptime(gr::date(2022,6,1),pt::hours(23)+pt::minutes(59));
    // ptr declarations
    StudentPtr student = make_shared<Student>();
    PassengerPtr p = make_shared<Passenger>("Name", "LastName", "PESEL123456", student);
    RoutePtr r = make_shared<Route>("IC 4122", "Poznan", "Krakow", 383, time1, time2);
    TrainPtr t = make_shared<Polregio>("Ford 1234", 0.2, 123);
    TicketPtr tik = make_shared<Ticket>(hehe, p, r, t, time3);
    TrainPtr tomek = make_shared<Polregio>("Tomaszek", 0.56, 250);
    // couts
    cout << p->getInfo() <<endl;
    cout << p->getPassengerDiscount(student)<<endl;
    cout << r->getInfo();
    cout << tik->getInfo();
    cout << "\n" << tomek->getInfo();
    return 0;
}
