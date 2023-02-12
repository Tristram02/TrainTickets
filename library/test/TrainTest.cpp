#include <boost/test/unit_test.hpp>
#include "model/Train.h"
#include "model/Polregio.h"
#include "model/LKA.h"
#include "model/Intercity.h"
#include "typedefs.h"

struct TestSuiteTrainFixture{
    const string testTrainNumber1 = "T123456";
    const string testTrainNumber2 = "T123457";
    const string testTrainNumber3 = "T123458";
    const double testBasePrice = 1.3;
    const int testCapacity = 200;

    TrainPtr p;
    TrainPtr l;
    TrainPtr i;

    TestSuiteTrainFixture()
    {
        p = make_shared<Polregio>(testTrainNumber1,testBasePrice,testCapacity);
        l = make_shared<LKA>(testTrainNumber2,testBasePrice,testCapacity);
        i = make_shared<Intercity>(testTrainNumber3,testBasePrice,testCapacity);
    }

    ~TestSuiteTrainFixture() = default;
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteTrain, TestSuiteTrainFixture)

    BOOST_AUTO_TEST_CASE(ConstructorTest)
    {
        BOOST_TEST(p->getTrainNumber() == testTrainNumber1);
        BOOST_TEST(p->getBasePrice() == testBasePrice);
        BOOST_TEST(p->getCapacity() == testCapacity);
        BOOST_TEST(l->getTrainNumber() == testTrainNumber2);
        BOOST_TEST(l->getBasePrice() == testBasePrice);
        BOOST_TEST(l->getCapacity() == testCapacity);
        BOOST_TEST(i->getTrainNumber() == testTrainNumber3);
        BOOST_TEST(i->getBasePrice() == testBasePrice);
        BOOST_TEST(i->getCapacity() == testCapacity);
    }

    BOOST_AUTO_TEST_CASE(ConstructorExceptionsTest)
    {
        BOOST_REQUIRE_THROW(TrainPtr t = make_shared<Polregio>("", 1.5, 200), logic_error);
        BOOST_REQUIRE_THROW(TrainPtr t = make_shared<LKA>("T456", -1.5, 200), logic_error);
        BOOST_REQUIRE_THROW(TrainPtr t = make_shared<Intercity>("T456", 1.5, -200), logic_error);
    }

BOOST_AUTO_TEST_SUITE_END()