#include "Employee.h" 
#include "Division.h" 
 
 
#include "JobDescription.h" 
#include <iostream> 
#include "Spouse.h" 
#include "Child.h" 
using namespace std; 
 
Employee::Employee() 
    : company_id(0), title(""), startDate(""), division(Division()),  
      jobDescriptions(), spouse(nullptr), children() {} 
 
Employee::Employee(const string& name, const string& ssn, int age,  
                   int company_id, const string& title, const string& startDate, 
                   const Division& division, const vector<JobDescription> jobDescriptions, 
                   Spouse* spouse, const vector<Child> children)  
    : Person(name, ssn, age), company_id(company_id), title(title), 
      startDate(startDate), division(division), jobDescriptions(jobDescriptions), 
      spouse(spouse), children(children) {} 
int Employee::getCompanyID() const { 
    return company_id; 
} 
string Employee::getStartDate() const { 
    return startDate; 
} 
string Employee::getTitle() const { 
    return title; 
} 
Division& Employee :: getDivision() { 
    return division; 
} 
vector<JobDescription>& Employee:: getJobDescriptions() { 
    return jobDescriptions; 
} 
vector<Child>& Employee::getChildren() { 
    return children; 
} 
Spouse* Employee::getSpouse() const { 
    return spouse; 
 
 
} 
void Employee::setCompanyID(int company_id) { 
    this->company_id = company_id; 
} 
void Employee::setTitle(const string& title) { 
    this->title = title; 
} 
void Employee::setStartDate(const string& startDate) { 
    this->startDate = startDate; 
} 
void Employee::setDivision(Division& division) { 
    this->division = division; 
} 
void Employee::setSpouse(Spouse* spouse) { 
    this->spouse = spouse; 
} 
void Employee::setJobDescriptions(vector<JobDescription> jobDescriptions) { 
    this->jobDescriptions = jobDescriptions; 
} 
void Employee::addJobDescription(const JobDescription& jobDescription) { 
    jobDescriptions.push_back(jobDescription); 
} 
void Employee::addChild(const Child& child) { 
    children.push_back(child); 
} 