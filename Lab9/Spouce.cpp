#include "Spouse.h" 
using namespace std; 
Spouse::Spouse(): annDate(""){} 
Spouse:: Spouse(const string& name, const string& ssn, int age, 
const string& annDate): 
Person(name, ssn, age), annDate(annDate){} 
 
string Spouse:: getAnnDate() const {return annDate;} 
 
void Spouse:: setAnnDate(const string& annDate){ 
    this->annDate=annDate; 
} 