#include "Child.h"

Child::Child() : Person(), favoriteToy("") {}

Child::Child(const string& name, const string& ssn, int age, const string& favoriteToy)
    : Person(name, ssn, age), favoriteToy(favoriteToy) {}

string Child::getFavoriteToy() const { return favoriteToy; }
void Child::setFavoriteToy(const string& favoriteToy) { this->favoriteToy = favoriteToy; }
