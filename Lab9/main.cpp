#include "Employee.h"
#include "Division.h"
#include "JobDescription.h"
#include "Spouse.h"
#include "Child.h"

#include <vector>
#include <iostream>

int main() {
    // Хэлтсүүд
    Division d1("Sales");
    Division d2("Engineering");
    Division d3("HR");

    // Ажлын тодорхойлолтууд
    JobDescription jd1("Marketing");
    JobDescription jd2("Civil Engineer");
    JobDescription jd3("Business Admin");
    JobDescription jd4("Software Engineer");
    JobDescription jd5("Teacher");

    // Ажилчид
    Employee e1("Alice", "111-22-3333", 30, "C001", "Manager", "2020-01-01", d1);
    Employee e2("Bob", "222-33-4444", 28, "C002", "Engineer", "2019-05-10", d2);
    Employee e3("Charlie", "333-44-5555", 35, "C003", "HR Specialist", "2018-03-20", d3);

    // Ажлын тодорхойлолтууд нэмэх
    e1.addJobDescription(jd1);
    e1.addJobDescription(jd3);

    e2.addJobDescription(jd2);
    e2.addJobDescription(jd4);

    e3.addJobDescription(jd3);
    e3.addJobDescription(jd5);

    // Ханиуд
    Spouse s1("Emma", "444-55-6666", 29, "2015-06-15");
    Spouse s2("Lily", "555-66-7777", 27, "2017-08-20");
    Spouse s3("Sophia", "666-77-8888", 32, "2012-11-11");

    e1.setSpouse(&s1);
    e2.setSpouse(&s2);
    e3.setSpouse(&s3);

    // Хүүхдүүд
    e1.addChild(Child("Tom", "777-88-9999", 5, "Lego"));
    e1.addChild(Child("Lucy", "888-99-0000", 3, "Doll"));

    e2.addChild(Child("Jake", "999-00-1111", 4, "Car"));

    // Бүх мэдээлэл хэвлэх
    e1.print();
    e2.print();
    e3.print();

    return 0;
}
