#ifndef DIVISION_H
#define DIVISION_H

#include <string>
#include <iostream>
using namespace std;

// Хэлтэс
class Division {
private:
    string divisionName;

public:
    Division();
    Division(const string& name);

    string getDivisionName() const;
    void setDivisionName(const string& name);

    friend ostream& operator<<(ostream& os, const Division& division);
};

#endif
