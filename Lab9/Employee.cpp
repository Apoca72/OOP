#include "Employee.h"

Employee::Employee()
    : Person(), companyID(""), title(""), startDate(""), division(), spouse(nullptr) {}

Employee::Employee(const string& name, const string& ssn, int age, const string& companyID,
                   const string& title, const string& startDate, const Division& division)
    : Person(name, ssn, age), companyID(companyID), title(title), startDate(startDate), division(division), spouse(nullptr) {}

void Employee::addJobDescription(const JobDescription& job) {
    jobDescriptions.push_back(job);
}

void Employee::addChild(const Child& child) {
    children.push_back(child);
}

void Employee::setSpouse(Spouse* spouse) {
    this->spouse = spouse;
}

void Employee::print() const {
    cout << "Нэр: " << name << ", РД: " << ssn << ", Нас: " << age << endl;
    cout << "Компанийн ID: " << companyID << ", Албан тушаал: " << title << ", Эхэлсэн огноо: " << startDate << endl;
    cout << "Хэлтэс: " << division << endl;

    cout << "Ажлын тодорхойлолт: ";
    for (const auto& job : jobDescriptions) {
        cout << job << " | ";
    }
    cout << endl;

    if (spouse != nullptr) {
        cout << "Гэрлэсэн хань: " << spouse->getName() << ", Ойн өдөр: " << spouse->getAnniversaryDate() << endl;
    } else {
        cout << "Гэрлээгүй." << endl;
    }

    if (!children.empty()) {
        cout << "Хүүхдүүд: " << endl;
        for (const auto& child : children) {
            cout << " - " << child.getName() << " (Дуртай тоглоом: " << child.getFavoriteToy() << ")" << endl;
        }
    } else {
        cout << "Хүүхэд байхгүй." << endl;
    }

    cout << "----------------------------------------" << endl;
}
