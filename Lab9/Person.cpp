#include "Person.h" 
using namespace std; 
Person:: Person(): name(""), ssn(""), age(0){} 
Person::Person(const string& name, const string& ssn, int age ) 
: name(name), ssn(ssn), age(age){} 
 
string Person:: getName() const {return name;} 
string Person:: getSSN() const {return ssn;} 
int Person:: getAge() const {return age;} 
void Person:: setName(const string& name){ 
    this->name=name; 
} 
void Person:: setSSN(const string& ssn){ 
    this->ssn=ssn; 
} 
void Person:: setAge(int age){ 
    this->age=age; 
} 