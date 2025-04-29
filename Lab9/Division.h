<<<<<<< HEAD
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
 
=======
#ifndef DIVISION_H
#define DIVISION_H

#include <string>
using namespace std;

class Division {
private:
    string divisionName;

public:
    Division(string name);
    string getDivisionName() const;
    void setDivisionName(string name);
};

#endif
>>>>>>> 36e62062b213de10188b35a9c28fd1a8c2b3f747
