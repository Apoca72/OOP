#include <iostream> 
#include "Employee.h" 
#include "Division.h" 
#include "JobDescription.h" 
#include "Spouse.h" 
#include "Child.h" 
#include <string> 
#include <vector> 
 
int main(){ 
    Division d[3]; 
    JobDescription jd[5]; 
    Employee e[3]; 
 
    d[0].setDivisionName("Sales"); 
    d[1].setDivisionName("Engineering"); 
    d[2].setDivisionName("Human resource"); 
 
    jd[0].setDescription("Marketing"); 
    jd[1].setDescription("Civil engineer"); 
    jd[2].setDescription("Business Administration"); 
    jd[3].setDescription("Software engineer"); 
    jd[4].setDescription("Teacher"); 
 
    for(int i=0; i<3; i++){ 
        e[i].setDivision(d[i]); 
    } 
 
 
 
    for(int i=0; i<3; i++){ 
        e[i].addJobDescription(jd[i]); 
    } 
 
    e[0].addJobDescription(jd[3]); 
    e[1].addJobDescription(jd[4]); 
 
    Spouse s[3]; 
    Child c[3]; 
 
    for(int i=0; i<3; i++){ 
        e[i].setSpouse(&s[i]); 
    } 
 
    for(int i=0; i<3; i++){ 
        e[i].addChild(c[i]); 
    } 
 
    int id[3]; 
     
    for(int i=0; i<3; i++){ 
        e[i].setCompanyID(id[i]); 
    } 
 
    e[0].setName("Jargal"); 
    e[1].setName("Tulga"); 
    e[2].setName("Naran"); 
 
    e[0].setAge(21); 
    e[1].setAge(25); 
    e[2].setAge(23); 
 
    e[0].setTitle("Title1"); 
    e[1].setTitle("Title2"); 
    e[2].setTitle("Title3"); 
 
 
 
    e[0].setStartDate("2024-10-01"); 
    e[1].setStartDate("2024-12-01"); 
    e[2].setStartDate("2024-11-01");  
 
    e[0].setCompanyID(1); 
    e[1].setCompanyID(2); 
    e[2].setCompanyID(3); 
 
    cout<< "Employees information:\n"<<endl; 
    for(int i=0; i<3; i++){ 
        cout<<"Emplyee :"<< i+1<<endl; 
        cout<<"Company id: "<< e[i].getCompanyID()<<endl; 
        cout<<"Title: "<<e[i].getTitle()<<endl; 
        cout<<"Start Date: "<< e[i].getStartDate()<<endl; 
        cout<<"Name: "<< e[i].getName()<<endl; 
        cout<<"Age: "<< e[i].getAge()<<endl; 
        cout<<"Division: " << e[i].getDivision()<<endl; 
        vector<JobDescription> jobs=e[i].getJobDescriptions(); 
        for(const auto& job: jobs){ 
            cout<<"Job: "<<job<<", "; 
        } 
        cout<<endl; 
 
        cout<< "Spouse:"<< (e[i].getSpouse() ? "Yes" : "No")<< endl; 
        cout<<"Number of Children: "<<e[i].getChildren().size()<<endl; 
    } 
    return 0; 
} 