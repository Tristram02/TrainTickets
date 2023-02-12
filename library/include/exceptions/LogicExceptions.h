#ifndef KOLEJE_BILETY_LOGICEXCEPTIONS_H
#define KOLEJE_BILETY_LOGICEXCEPTIONS_H
#include <stdexcept>
#include <string>

using namespace std;

class LogicExceptions : public logic_error{
public:
    explicit LogicExceptions(const string &error) : logic_error(error){}
};

#endif //KOLEJE_BILETY_LOGICEXCEPTIONS_H
