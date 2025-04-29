#ifndef JOBDESCRIPTION_H
#define JOBDESCRIPTION_H

#include <string>
#include <iostream>
using namespace std;

// Ажлын тодорхойлолт
class JobDescription {
private:
    string description;

public:
    JobDescription();
    JobDescription(const string& description);

    string getDescription() const;
    void setDescription(const string& description);

    friend ostream& operator<<(ostream& os, const JobDescription& job);
};

#endif
