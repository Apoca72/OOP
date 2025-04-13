#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

// Person классыг тодорхойлох
// Энэ нь Spouse, Employee, Child классуудын үндсэн (parent) класс юм.
class Person {
private:
    string Name;   // Хүний нэр
    string SSNum;  // Нийгмийн даатгалын дугаар
    int Age;       // Нас

public:
    // Конструктор
    Person(string name = "", string ssnum = "", int age = 0)
        : Name(name), SSNum(ssnum), Age(age) {}

    // Getter болон Setter функцууд
    string getName() const { return Name; }
    string getSSNum() const { return SSNum; }
    int getAge() const { return Age; }

    void setName(string name) { Name = name; }
    void setSSNum(string ssnum) { SSNum = ssnum; }
    void setAge(int age) { Age = age; }
};

// Spouse (нөхөр/эхнэр) классыг тодорхойлох
// Энэ нь Person классыг өргөжүүлсэн (унасан) класс юм.
class Spouse : public Person {
private:
    string AnniversaryDate;  // Гэрлэлтийн ой тэмдэглэх огноо

public:
    Spouse(string name = "", string ssnum = "", int age = 0, string annDate = "")
        : Person(name, ssnum, age), AnniversaryDate(annDate) {}

    string getAnniversaryDate() const { return AnniversaryDate; }
    void setAnniversaryDate(string annDate) { AnniversaryDate = annDate; }
};

// Child (хүүхэд) классыг тодорхойлох
// Энэ нь мөн Person классыг өргөжүүлсэн класс юм.
class Child : public Person {
private:
    string FavoriteToy;  // Хүүхдийн дуртай тоглоом

public:
    Child(string name = "", string ssnum = "", int age = 0, string favToy = "")
        : Person(name, ssnum, age), FavoriteToy(favToy) {}

    string getFavoriteToy() const { return FavoriteToy; }
    void setFavoriteToy(string favToy) { FavoriteToy = favToy; }
};

// Division классыг тодорхойлох
class Division {
private:
    string DivisionName;  

public:
    Division(string divName = "") : DivisionName(divName) {}

    string getDivisionName() const { return DivisionName; }
    void setDivisionName(string divName) { DivisionName = divName; }
};

// JobDescription классыг тодорхойлох
class JobDescription {
private:
    string Description;  

public:
    JobDescription(string desc = "") : Description(desc) {}

    string getDescription() const { return Description; }
    void setDescription(string desc) { Description = desc; }
};

// Employee классыг тодорхойлох
// Person классыг өргөжүүлсэн класс 
class Employee : public Person {
private:
    string CompanyID;   // Компаний ID
    string Title;       // Албан тушаал
    string StartDate;   // Ажилд орсон огноо

    // Дараах хувьсагчид нь классуудын хоорондын харилцааг харуулна
    Spouse* spouse;                     // Нөхөр/эхнэртэй байх (0..1 харьцаа)
    vector<Child> children;             // Хүүхдүүдийн жагсаалт (0..n харьцаа)
    Division* division;                 // Хэлтэс (1 харьцаа)
    vector<JobDescription*> jobDescriptions;  // Ажлын тодорхойлолт (1..n харьцаа)

public:
    // Конструктор - Даалгаварт заасны дагуу Division болон JobDescription заавал шаардагдана (1, 1..n харьцаа)
    Employee(string name = "", string ssnum = "", int age = 0,
             string companyID = "", string title = "", string startDate = "",
             Division* div = nullptr, JobDescription* jd = nullptr)
        : Person(name, ssnum, age), CompanyID(companyID), Title(title), StartDate(startDate),
          spouse(nullptr), division(div) {
        // 1 харьцааг шалгаж байна (заавал 1 Division байх ёстой)
        if (division == nullptr) {
            cerr << "Алдаа: Ажилтан заавал нэг хэлтэст харьяалагдах ёстой!" << endl;
            exit(1);
        }
        // 1..n харьцааг шалгаж байна (хамгийн багадаа 1 JobDescription байх ёстой)
        if (jd == nullptr) {
            cerr << "Алдаа: Ажилтан заавал хамгийн багадаа нэг ажлын тодорхойлолттой байх ёстой!" << endl;
            exit(1);
        }
        // Анхны JobDescription-г нэмж байна (1..n харьцааны хамгийн багадаа 1 гэдгийг хангах)
        jobDescriptions.push_back(jd);
    }

    // Getter болон Setter функцууд
    string getCompanyID() const { return CompanyID; }
    string getTitle() const { return Title; }
    string getStartDate() const { return StartDate; }

    void setCompanyID(string companyID) { CompanyID = companyID; }
    void setTitle(string title) { Title = title; }
    void setStartDate(string startDate) { StartDate = startDate; }

    // Харилцаа зохицуулах функцууд
    // 0..1 харьцааг хангах функц - Даалгаварт заасны дагуу Spouse тохируулах
    void setSpouse(Spouse* s) { spouse = s; }
    Spouse* getSpouse() const { return spouse; }
    
    // 0..n харьцааг хангах функц - Даалгаварт заасны дагуу Child нэмэх
    void addChild(const Child& child) { children.push_back(child); }
    vector<Child> getChildren() const { return children; }
    
    // 1 харьцааг хангах функц - Даалгаварт заасны дагуу Division тохируулах
    void setDivision(Division* div) { 
        if (div == nullptr) {
            cerr << "Алдаа: Хэлтэс null байж болохгүй!" << endl;
            return;
        }
        division = div; 
    }
    Division* getDivision() const { return division; }
    
    // 1..n харьцааг хангах функц - Даалгаварт заасны дагуу JobDescription нэмэх
    void addJobDescription(JobDescription* jd) {
        if (jd != nullptr) {
            jobDescriptions.push_back(jd);
        }
    }
    vector<JobDescription*> getJobDescriptions() const { return jobDescriptions; }
    
    // Ажилтны бүх мэдээллийг хэвлэх функц
    void displayInfo() const {
        cout << "--------- Ажилтны мэдээлэл ---------" << endl;
        cout << "Нэр: " << getName() << endl;
        cout << "НД-ын дугаар: " << getSSNum() << endl;
        cout << "Нас: " << getAge() << endl;
        cout << "Компаний ID: " << CompanyID << endl;
        cout << "Албан тушаал: " << Title << endl;
        cout << "Ажилд орсон огноо: " << StartDate << endl;

        // Division мэдээллийг хэвлэх (1 харьцаа)
        cout << "Хэлтэс: " << division->getDivisionName() << endl;

        // JobDescription мэдээллийг хэвлэх (1..n харьцаа)
        cout << "Ажлын тодорхойлолт: " << endl;
        for (size_t i = 0; i < jobDescriptions.size(); i++) {
            cout << "  " << (i+1) << ". " << jobDescriptions[i]->getDescription() << endl;
        }

        // Spouse мэдээллийг хэвлэх (0..1 харьцаа)
        cout << "Нөхөр/эхнэр: ";
        if (spouse == nullptr) {
            cout << "Байхгүй" << endl;
        } else {
            cout << spouse->getName() << " (Гэрлэсэн огноо: " << spouse->getAnniversaryDate() << ")" << endl;
        }

        // Child мэдээллийг хэвлэх (0..n харьцаа)
        cout << "Хүүхдүүд: " << endl;
        if (children.empty()) {
            cout << "  Байхгүй" << endl;
        } else {
            for (size_t i = 0; i < children.size(); i++) {
                cout << "  " << (i+1) << ". " << children[i].getName() 
                      << " (Дуртай тоглоом: " << children[i].getFavoriteToy() << ")" << endl;
            }
        }
        cout << "---------------------------------------" << endl;
    }
};

int main() {

    // UTF-8 кодчлолыг тохируулах
    SetConsoleOutputCP(CP_UTF8);
    
    // Даалгаварт заасны дагуу Division объектууд үүсгэж байна
    Division itDivision("Мэдээллийн технологийн хэлтэс");
    Division hrDivision("Хүний нөөцийн хэлтэс");
    Division marketingDivision("Маркетингийн хэлтэс");
    
    // Даалгаварт заасны дагуу JobDescription объектууд үүсгэж байна
    JobDescription programmer("Программ хөгжүүлэгч");
    JobDescription manager("Төслийн менежер");
    JobDescription designer("UI/UX Дизайнер");
    JobDescription hrManager("Хүний нөөцийн менежер");
    JobDescription recruiter("Ажилтан элсүүлэгч");
    JobDescription marketingManager("Маркетингийн менежер");
    
    // Даалгаварт заасны дагуу Employee объектуудыг үүсгэж, 
    // тус бүрд Division болон JobDescription заавал оноож байна
    Employee john("Болд Дорж", "АБ123456", 35, "EMP001", "Ахлах хөгжүүлэгч", "2018-05-15", 
                 &itDivision, &programmer);
    // Нэмэлт JobDescription оноож байна (1..n харьцааг харуулах)
    john.addJobDescription(&manager);
    
    Employee jane("Нарантуяа Чимэд", "ГД456789", 28, "EMP002", "HR мэргэжилтэн", "2020-02-10", 
                 &hrDivision, &hrManager);
    // Нэмэлт JobDescription оноож байна (1..n харьцааг харуулах)
    jane.addJobDescription(&recruiter);
    
    Employee alex("Цэрэн Пүрэв", "ЖЗ987654", 32, "EMP003", "Бүтээлч захирал", "2019-07-20", 
                 &marketingDivision, &marketingManager);
    // Нэмэлт JobDescription оноож байна (1..n харьцааг харуулах)
    alex.addJobDescription(&designer);
    
    // Spouse объектууд үүсгэж байна
    Spouse johnSpouse("Номин Батаа", "ИК876543", 33, "2015-06-12");
    Spouse janeSpouse("Баатар Хишигт", "ЛМ654321", 30, "2019-08-23");
    
    // Child объектууд үүсгэж байна
    Child johnChild1("Хулан Болд", "НО112233", 8, "Хүүхэлдэй");
    Child johnChild2("Тэмүүлэн Болд", "РС334455", 6, "Машин");
    Child janeChild1("Цэцэг Баатар", "ТУ556677", 5, "Баавгай");
    
    // Employee-д Spouse оноож байна (0..1 харьцаа)
    john.setSpouse(&johnSpouse);
    jane.setSpouse(&janeSpouse);
    // alex-д Spouse оноохгүй (0..1 харьцааг харуулах)
    
    // Employee-д Child нэмж байна (0..n харьцаа)
    john.addChild(johnChild1);
    john.addChild(johnChild2);
    jane.addChild(janeChild1);
    // alex-д Child нэмэхгүй (0..n харьцааг харуулах)
    
    // Employee бүрийн бүх мэдээллийг хэвлэж байна
    john.displayInfo();
    cout << endl;
    jane.displayInfo();
    cout << endl;
    alex.displayInfo();
    
    return 0;
}
