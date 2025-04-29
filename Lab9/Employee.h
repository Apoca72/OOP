#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include "Division.h"
#include "JobDescription.h"
#include "Child.h"
#include "Spouse.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

// Ажилтан
class Employee : public Person {
private:
    string companyID;
    string title;
    string startDate;
    Division division;
    vector<JobDescription> jobDescriptions;
    vector<Child> children;
    Spouse* spouse;

public:
    Employee();
    Employee(const string& name, const string& ssn, int age, const string& companyID,
             const string& title, const string& startDate, const Division& division);

    void addJobDescription(const JobDescription& job); // Ажлын үүрэг нэмэх
    void addChild(const Child& child);                 // Хүүхэд нэмэх
    void setSpouse(Spouse* spouse);                    // Гэрлэх
    void print() const;                                // Мэдээлэл хэвлэх
};

#endif
