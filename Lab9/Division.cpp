#include "Division.h" 
using namespace std; 
Division:: Division(): divisionName("Unknown"){} 
 
 
Division:: Division(const string& divisionName):  
divisionName(divisionName){} 
string Division:: getDivisionName() const {return divisionName;} 
void Division:: setDivisionName(const string& divisionName){ 
    this->divisionName=divisionName; 
} 
ostream& operator<<(ostream& os, const Division& division) { 
    os << division.divisionName; 
    return os; 
} 