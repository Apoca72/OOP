#ifndef DIVISION_H 
#define DIVISION_H 
#include <string> 
using namespace std; 
 
class Division{ 
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
 