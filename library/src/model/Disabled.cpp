//
// Created by student on 29.05.2022.
//

#include "../../include/model/Disabled.h"

double Disabled::getPassengerDiscount()
{
    return 0.49; // znizka 51% zapisana jako czesc ceny normalnej
}
string Disabled::getPassengerTypeInfo()
{
    return "Disabled";
}