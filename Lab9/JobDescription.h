#ifndef JOBDESCRIPTION_H 
#define JOBDESCRIPTION_H 
#include <string> 
using namespace std; 
 
class JobDescription{ 
    private: 
    string description; 
 
    public: 
    JobDescription(); 
    JobDescription(const string& description); 
    string getDescription() const; 
    void setDescription(const string& description); 
 
    friend ostream& operator<<(std::ostream& os, const JobDescription& job); 
}; 
#endif 
 