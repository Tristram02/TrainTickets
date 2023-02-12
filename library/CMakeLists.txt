cmake_minimum_required(VERSION 3.4)

project(Library)

set(SOURCE_FILES src/model/Repository.cpp src/model/Passenger.cpp src/model/Train.cpp src/model/Polregio.cpp src/model/LKA.cpp src/model/Intercity.cpp
                src/model/Disabled.cpp src/model/Disciple.cpp src/model/Normal.cpp src/model/PhDStudent.cpp src/model/PassengerType.cpp
                 src/managers/PassengerManager.cpp src/managers/TrainManager.cpp src/managers/TicketManager.cpp
                src/model/Senior.cpp src/model/Student.cpp
                 include/typedefs.h
                 include/exceptions/LogicExceptions.h include/exceptions/ParameterExceptions.h src/model/Ticket.cpp include/model/Ticket.h src/model/Route.cpp include/model/Route.h)

add_library(Library ${SOURCE_FILES})

target_include_directories(Library PUBLIC include)

enable_testing()

find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)
find_package(Boost REQUIRED COMPONENTS thread)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_FILES test/master.cpp test/TrainTest.cpp test/RouteTest.cpp test/PassengerTest.cpp test/TicketTest.cpp)

add_executable(LibraryTest ${SOURCE_TEST_FILES})

target_link_libraries(LibraryTest Library ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

add_test(LibraryTest1 LibraryTest
        --report_level=detailed
        --log_level=all
        --color_output=yes)