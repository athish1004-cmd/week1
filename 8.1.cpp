#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual void name() const = 0;
    virtual ~Shape() {}
}; 

class circle : public Shape {
    double r;
public:
    circle(double r) : r(r) {}
    double area() const override { return 3.14159 * r * r; }
    void name() const override { cout << "circle"; }
};

class square : public Shape {
    double S;
public:
    square(double S) : S(S) {}
    double area() const override { return S * S; }
    void name() const override { cout << "square"; }
};

int main() {
    Shape* shapes[] = { new circle(2.0), new square(3.0) };
    
    for (Shape* s : shapes) {
        s->name();
        cout << " area=" << s->area() << endl;
    }
    
    for (Shape* s : shapes) {
        delete s;
    }
    
    return 0;
}
