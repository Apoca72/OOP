#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
protected:
    string name;
    string ssn;
    int age;

public:
    Person();
    Person(const string& name,const string& ssn, int age);
    string getName() const;
    string getSSN() const;
    int getAge() const;
    void setName(const string& name);
    void setSSN(const string& ssn);
    void setAge(const int age);
};

#endif
