#include <iostream>
using namespace std;

class Player {
private:
    string name;
public:
    // Бүх үйлдлийг constructor дотор хийж байна
    Player(string name) {
        this->name = name; // 'this' нь тухайн объектын name хувьсагчийг зааж байна
        cout << "Player created: " << this->name << endl;
    }
};

int main() {
    Player p("Temka");
    return 0;
}
