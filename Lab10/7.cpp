#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

// Shape эх класс
class Shape {
protected:
    static int count; // Бүх объектуудыг тоолох статик хувьсагч
    double dimension; // Радиус, талын урт гэх мэт
public:
    Shape(double dim) : dimension(dim) {
        count++;
    }
    virtual ~Shape() {
        count--;
    }

    static int getCount() { // Статик гишүүн функц
        return count;
    }

    virtual double area() const = 0;       // Жинхэнэ хийсвэр функц
    virtual double perimeter() const = 0; // Жинхэнэ хийсвэр функц

    virtual void display() const = 0; // Дүрсийн мэдээллийг хэвлэх
};
int Shape::count = 0; // Статик хувьсагчийн эхлэлийн утга

// _2DShape класс (Shape-ээс удамшсан)
class _2DShape : public Shape {
protected:
    double x, y; // Координат
public:
    _2DShape(double x, double y, double dim) : Shape(dim), x(x), y(y) {}
};

// Circle класс (_2DShape-ээс удамшсан)
class Circle : public _2DShape {
public:
    Circle(double x, double y, double r) : _2DShape(x, y, r) {}

    double area() const override {
        return M_PI * this->dimension * this->dimension; // this ашигласан
    }

    double perimeter() const override {
        return 2 * M_PI * this->dimension; // this ашигласан
    }

    void display() const override {
        cout << "Circle - Tuv: (" << x << ", " << y
             << "), Radius: " << dimension << ", Talbai: " << area()
             << ", Perimeter: " << perimeter() << endl;
    }
};

// Square класс (_2DShape-ээс удамшсан)
class Square : public _2DShape {
public:
    Square(double x, double y, double side) : _2DShape(x, y, side) {}

    double area() const override {
        return this->dimension * this->dimension; // this ашигласан
    }

    double perimeter() const override {
        return 4 * this->dimension; // this ашигласан
    }

    void display() const override {
        cout << "Square - Top-Left Corner: (" << x << ", " << y
             << "), Taliin urt: " << dimension << ", Talbai: " << area()
             << ", Perimeter: " << perimeter() << endl;
    }
};

// Triangle класс (_2DShape-ээс удамшсан)
class Triangle : public _2DShape {
public:
    Triangle(double x, double y, double side) : _2DShape(x, y, side) {}

    double area() const override {
        return (sqrt(3) / 4) * this->dimension * this->dimension; // this ашигласан
    }

    double perimeter() const override {
        return 3 * this->dimension; // this ашигласан
    }

    void display() const override {
        cout << "Triangle - Deed oroi: (" << x << ", " << y
             << "), Taliin urt: " << dimension << ", Talbai: " << area()
             << ", Perimeter: " << perimeter() << endl;
    }
};

// Дүрсүүдийг талбайгаар нь эрэмбэлэхэд ашиглах функц
bool compareArea(const Shape* a, const Shape* b) {
    return a->area() < b->area();
}

// Дүрсүүдийг периметрээр нь эрэмбэлэхэд ашиглах функц
bool comparePerimeter(const Shape* a, const Shape* b) {
    return a->perimeter() < b->perimeter();
}


