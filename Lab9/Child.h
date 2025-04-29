#ifndef CHILD_H
#define CHILD_H

#include "Person.h"
#include <string>

// Хүүхэд класс (Person-оос өвлөсөн)
class Child : public Person {
private:
    string favoriteToy; // Хамгийн дуртай тоглоом

public:
    Child();
    Child(const string& name, const string& ssn, int age, const string& favoriteToy);

    string getFavoriteToy() const;
    void setFavoriteToy(const string& favoriteToy);
};

#endif
