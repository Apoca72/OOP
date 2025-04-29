#ifndef SPOUSE_H
#define SPOUSE_H

#include "Person.h"
#include <string>

// Нөхөр/Эхнэр класс (Person-оос өвлөсөн)
class Spouse : public Person {
private:
    string anniversaryDate; // Ойн өдөр

public:
    Spouse();
    Spouse(const string& name, const string& ssn, int age, const string& anniversaryDate);

    string getAnniversaryDate() const;
    void setAnniversaryDate(const string& anniversaryDate);
};

#endif
