#ifndef KOLEJE_BILETY_PARAMETEREXCEPTIONS_H
#define KOLEJE_BILETY_PARAMETEREXCEPTIONS_H
#include <stdexcept>
#include <string>

using namespace std;

class ParameterExceptions : public logic_error{
public:
    explicit ParameterExceptions(const string &error) : logic_error(error) {}
};

#endif //KOLEJE_BILETY_PARAMETEREXCEPTIONS_H
