#include <boost/test/unit_test.hpp>
#include "model/Passenger.h"
#include "typedefs.h"
#include "model/Disabled.h"
//#include "boost/date_time.hpp"

//namespace pt = boost::posix_time;
//namespace gr = boost::gregorian;
struct TestSuitePassengerFixture{
    const string testName = "Bartosz";
    const string testLastName = "Wlodarski";
    const string testPassengerID = "01232123456";
    DisabledPtr pstype = make_shared<Disabled>();
    PassengerPtr testPassenger;
    TestSuitePassengerFixture()
    {
         testPassenger = make_shared<Passenger>(testName, testLastName, testPassengerID, pstype);
    }

    ~TestSuitePassengerFixture() = default;
};

BOOST_FIXTURE_TEST_SUITE(TestSuitePassenger, TestSuitePassengerFixture)

    BOOST_AUTO_TEST_CASE(ConstructorTest)
    {
        BOOST_REQUIRE_EQUAL(testPassenger->getName(),testName);
        BOOST_REQUIRE_EQUAL(testPassenger->getLastName(),testLastName);
        BOOST_REQUIRE_EQUAL(testPassenger->getPassengerID(),testPassengerID);
        BOOST_REQUIRE_EQUAL(testPassenger->getPassengerType(),pstype);
    }

    BOOST_AUTO_TEST_CASE(ConstructorExceptionsTest)
    {
        BOOST_REQUIRE_THROW(PassengerPtr p = make_shared<Passenger>("", "drugie", "aj_di", pstype), logic_error);
        BOOST_REQUIRE_THROW(PassengerPtr p = make_shared<Passenger>("pierwsze", "", "aj_di", pstype), logic_error);
        BOOST_REQUIRE_THROW(PassengerPtr p = make_shared<Passenger>("pierwsze", "drugie", "", pstype), logic_error);
        BOOST_REQUIRE_THROW(PassengerPtr p = make_shared<Passenger>("pierwsze", "drugie", "aj_di", nullptr), logic_error);

    }

BOOST_AUTO_TEST_SUITE_END()//



