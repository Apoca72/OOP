#include "Spouse.h"

Spouse::Spouse() : anniversaryDate("") {}

Spouse::Spouse(const string& name, const string& ssn, int age, const string& anniversaryDate)
    : Person(name, ssn, age), anniversaryDate(anniversaryDate) {}

string Spouse::getAnniversaryDate() const { return anniversaryDate; }
void Spouse::setAnniversaryDate(const string& anniversaryDate) { this->anniversaryDate = anniversaryDate; }
