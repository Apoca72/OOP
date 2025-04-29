#include "JobDescription.h" 
using namespace std; 
JobDescription:: JobDescription(): description(""){} 
JobDescription:: JobDescription(const string& description): description(description){} 
string JobDescription:: getDescription() const {return description;} 
void JobDescription:: setDescription(const string& description){ 
 
 
    this->description=description; 
} 
ostream& operator<<(ostream& os, const JobDescription& job) { 
    os << job.description; 
    return os; 
} 