#include "Division.h"

Division::Division() : divisionName("Unknown") {}

Division::Division(const string& name) : divisionName(name) {}

string Division::getDivisionName() const { return divisionName; }
void Division::setDivisionName(const string& name) { this->divisionName = name; }

ostream& operator<<(ostream& os, const Division& division) {
    os << division.divisionName;
    return os;
}
