#ifndef CHILD_H 
#define CHILD_H 
#include <string> 
#include "Person.h" 
using namespace std; 
class Child: public Person{ 
    private: 
    string favToy; 
    public: 
    Child(); 
    Child(const string& name, const string& ssn, int age, const string& favToy); 
 
    string getFavToy() const; 
    void setFavToy(const string& favToy); 
}; 
#endif 