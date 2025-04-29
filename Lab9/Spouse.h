#ifndef SPOUSE_H 
#define SPOUSE_H 
#include <string> 
#include "Person.h" 
using namespace std; 
 
class Spouse: public Person{ 
    private: 
    string annDate; 
 
 
    public: 
    Spouse(); 
    Spouse(const string& name, const string& ssn, int age, const string& annDate); 
 
    string getAnnDate() const; 
    void setAnnDate(const string& annDate); 
}; 
#endif 