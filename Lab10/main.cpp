#include <iostream>
#include <cstdlib>
#include <ctime>
#include "templateLinkedList.cpp" // LinkedList класс
#include "7.cpp" // Shape, Circle, Square, Triangle классууд

using namespace std;

// LinkedList доторх элементүүдийг талбайгаар нь өсөхөөр сортлох функц
void sortByArea(LinkedList<Shape*>& list) {
    int n = list.length();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (list.get(j)->area() > list.get(j+1)->area()) {
                // pointer-уудыг солих
                Shape* temp = list.get(j);
                list.removeAt(j);
                list.insert(list.get(j), j);
                list.removeAt(j+1);
                list.insert(temp, j+1);
            }
        }
    }
}

int main() {
    srand(time(0)); // random seed

    LinkedList<Shape*> shapes;

    int n = rand() % 11 + 20; // 20-30 тооны объект үүсгэнэ
    for (int i = 0; i < n; ++i) {
        int shapeType = rand() % 3; // 0: Circle, 1: Square, 2: Triangle
        double x = rand() % 100;     // 0-99 хоорондох координат
        double y = rand() % 100;
        double size = rand() % 20 + 1; // 1-20 хооронд хэмжээ

        if (shapeType == 0)
            shapes.add(new Circle(x, y, size));
        else if (shapeType == 1)
            shapes.add(new Square(x, y, size));
        else
            shapes.add(new Triangle(x, y, size));
    }

    cout << "===== Ehnii baidal (sanamsargui uusgegdsen) =====" << endl;
    for (int i = 0; i < shapes.length(); ++i) {
        shapes.get(i)->display();
    }

    // Талбайгаар эрэмбэлэх
    sortByArea(shapes);

    cout << "\n===== Talbaigaar eremblegdsen baidal =====" << endl;
    for (int i = 0; i < shapes.length(); ++i) {
        shapes.get(i)->display();
    }

    // Дүрсүүдийг устгах (memory цэвэрлэх)
    for (int i = 0; i < shapes.length(); ++i) {
        delete shapes.get(i);
    }

    return 0;
}
