#include <boost/test/unit_test.hpp>
#include "model/Route.h"
#include "typedefs.h"
#include "boost/date_time.hpp"

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;
struct TestSuiteRouteFixture{
    const string testRouteID = "B3179UXY";
    const string testOrigin = "Lodz";
    const string testDestination = "Radomsko";
    const double testKilometers = 56.7;
    const pt::ptime testTime1 = pt::ptime(gr::date(2020,2,29),pt::hours(23)+pt::minutes(10));
    const pt::ptime testTime2 = pt::ptime(gr::date(2020,3,1),pt::hours(0)+pt::minutes(59));

    RoutePtr testRoute;

    TestSuiteRouteFixture()
    {
        testRoute = make_shared<Route>(testRouteID, testOrigin, testDestination, testKilometers, testTime1, testTime2);
    }

    ~TestSuiteRouteFixture() = default;
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRoute, TestSuiteRouteFixture)

    BOOST_AUTO_TEST_CASE(ConstructorTest)
    {
        BOOST_TEST(testRoute->getRouteID() == testRouteID);
        BOOST_TEST(testRoute->getOrigin() == testOrigin);
        BOOST_TEST(testRoute->getDestination() == testDestination);
        BOOST_TEST(testRoute->getKilometers() == testKilometers);
        BOOST_TEST(testRoute->getDepartureTime() == testTime1);
        BOOST_TEST(testRoute->getArrivalTime() == testTime2);
    }

    BOOST_AUTO_TEST_CASE(TravelTimeTest)
    {
        pt::time_period travelTime(testTime1, testTime2);
        BOOST_REQUIRE_EQUAL(travelTime, pt::time_period(testTime1, testTime1 + pt::hours(1) + pt::minutes(49)));
        // sprawdzanie z wartoscia oczekiwana 1:49
        pt::time_period travelTime2(testTime2, testTime1);
        BOOST_REQUIRE(travelTime2.is_null());
        // time period < 0 ma nie dzialac
    }

    BOOST_AUTO_TEST_CASE(ConstructorExceptionsTest)
    {
        BOOST_REQUIRE_THROW(Route r1("", "a", "b", 23, testTime1, testTime2), logic_error);
        BOOST_REQUIRE_THROW(Route r2("a", "", "b", 23, testTime1, testTime2), logic_error);
        BOOST_REQUIRE_THROW(Route r3("a", "b", "", 23, testTime1, testTime2), logic_error);
        BOOST_REQUIRE_THROW(Route r4("a", "b", "c", -183, testTime1, testTime2), logic_error);
        BOOST_REQUIRE_THROW(Route r5("a", "b", "c", 183,  pt::not_a_date_time, testTime2), logic_error);
        BOOST_REQUIRE_THROW(Route r6("a", "b", "c", 183,  testTime1, pt::not_a_date_time), logic_error);
    }

BOOST_AUTO_TEST_SUITE_END()//
// Created by student on 31.05.2022.
//

