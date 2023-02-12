//
// Created by student on 09.06.2022.
//
#include <boost/test/unit_test.hpp>
#include "model/Ticket.h"
#include "model/Passenger.h"
#include "model/Disabled.h"
#include "model/Route.h"
#include "model/Train.h"
#include "model/LKA.h"
#include "typedefs.h"
#include "boost/date_time.hpp"

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;
struct TestSuiteTicketFixture{
    // testowy passenger
    DisabledPtr pstype = make_shared<Disabled>();
    PassengerPtr testPassenger = make_shared<Passenger>("Maciej", "Stolarczyk", "71121171234", pstype);
    // testowy route
    pt::ptime time1=pt::ptime(gr::date(2022,2,22),pt::hours(22)+pt::minutes(54));
    pt::ptime time2=pt::ptime(gr::date(2022,2,22),pt::hours(23)+pt::minutes(41));
    RoutePtr testRoute = make_shared<Route>("IC 4122", "Poznan", "Krakow", 383, time1, time2);
    // testowy train
    TrainPtr testTrain = make_shared<LKA>("Ford 1234", 72.40, 123);
    // -------------
    // testowy ticket
    boost::uuids::uuid ticketID;
    pt::ptime testExpireDate = pt::ptime(gr::date(2020,3,2),pt::hours(23)+pt::minutes(10));
    pt::ptime timeNow = pt::second_clock::local_time();
    pt::ptime timeBeforeNow = timeNow - pt::minutes(20);
    pt::ptime timeAfterNow = timeNow + pt::minutes(40);
    const double testPrice = 6.37;
    const bool returned = false; // czy bilet jest zwrocony
    const bool used = true; // czy bilet jest uzyty
    TicketPtr testTicket;
    TicketPtr testTicket2;
    TestSuiteTicketFixture()
    {
        testTicket = make_shared<Ticket>(ticketID, testPassenger, testRoute, testTrain, timeBeforeNow, testPrice);
        testTicket2 = make_shared<Ticket>(ticketID, testPassenger, testRoute, testTrain, timeAfterNow, testPrice);

    }
    ~TestSuiteTicketFixture() = default;
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteTicket, TestSuiteTicketFixture)

    BOOST_AUTO_TEST_CASE(ConstructorTest)
    {
        BOOST_REQUIRE_EQUAL(testTicket->getTicketID(),ticketID);
        BOOST_REQUIRE_EQUAL(testTicket->getExpireDate(), timeBeforeNow);
        BOOST_REQUIRE_EQUAL(testTicket->getPassenger(), testPassenger);
        BOOST_REQUIRE_EQUAL(testTicket->getRoute(), testRoute);
        BOOST_REQUIRE_EQUAL(testTicket->getTrain(), testTrain);
        BOOST_REQUIRE_EQUAL(testTicket->getPrice(), testPrice);
        BOOST_REQUIRE_EQUAL(testTicket->isReturned(), false);
        BOOST_REQUIRE_EQUAL(testTicket->isUsed(), false);

    }

    BOOST_AUTO_TEST_CASE(ConstructorExceptionsTest)
    {
        // jeszcze nie mam exceptions
    }

    BOOST_AUTO_TEST_CASE(SetterTest)
    {
        BOOST_REQUIRE_EQUAL(testTicket->isReturned(), false);
        BOOST_REQUIRE_EQUAL(testTicket->isUsed(), false);
        testTicket->setReturned(true);
        testTicket->setUsed(true);
        BOOST_REQUIRE_EQUAL(testTicket->isReturned(), true);
        BOOST_REQUIRE_EQUAL(testTicket->isUsed(), true);
    }

    BOOST_AUTO_TEST_CASE(IsExpiredTest)
    {
        BOOST_REQUIRE_EQUAL(testTicket->isExpired(), true);
        BOOST_REQUIRE_EQUAL(testTicket2->isExpired(), false);
    }

BOOST_AUTO_TEST_SUITE_END()//




