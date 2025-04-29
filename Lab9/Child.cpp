#include"Child.h" 
using namespace std; 
 
Child:: Child():Person(), favToy(""){} 
Child:: Child(const string& name, const string& ssn, int age, const string& favToy): 
Person(name, ssn, age), favToy(favToy){} 
 
string Child:: getFavToy() const{return favToy;} 
 
void Child:: setFavToy(const string& favToy){ 
    this->favToy=favToy; 
} 