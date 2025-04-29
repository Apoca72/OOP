#ifndef EMPLOYEE_H 
#define EMPLOYEE_H 
 
#include "Person.h" 
#include "Division.h" 
#include "JobDescription.h" 
#include "Child.h" 
#include "Spouse.h" 
#include <string> 
#include <vector> 
using namespace std; 
class Employee : public Person { 
 
 
private: 
    int company_id; 
    string title; 
    string startDate; 
    Division division;  // 1..1 relationship stored as a value 
    vector<JobDescription> jobDescriptions;  // 1..n 
    vector<Child> children;  // 0..n 
    Spouse* spouse;  // 0..1 
 
public: 
    Employee(); 
    Employee(const string& name, const string& ssn, int age,  
             int company_id, const string& title, const string& startDate, 
             const Division& division, vector<JobDescription> jobDescriptions,  
             Spouse* spouse, vector<Child> children); 
    int getCompanyID() const; 
    string getStartDate() const; 
    string getTitle() const; 
    Division& getDivision();  
    vector<JobDescription>& getJobDescriptions(); 
    vector<Child>& getChildren(); 
    Spouse* getSpouse() const; 
 
    void setCompanyID(int company_id); 
    void setStartDate(const string& startDate); 
    void setTitle(const string& title); 
    void setDivision(Division& division);  
    void setJobDescriptions(vector<JobDescription> jobDescriptions);  
    void setSpouse(Spouse* spouse); 
 
    void addJobDescription(const JobDescription& jobDescription);  
    void addChild(const Child& child);  
}; 
#endif 