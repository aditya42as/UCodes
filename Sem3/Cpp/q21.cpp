/*Create a base class called shape. Use this class to store 
two double type values that could be used to compute the 
area of figures. Derive two specific classes called triangle 
and rectangle from base shape. Add to the base class, a 
member function get_data() to initialize base class data 
members and another member function display_area() to 
compute and display the area of figures. Make 
display_area() as a virtual function and redefine this 
function in the derived class to suit their requirements. 
Using these three classes, design a program that will 
accept dimensions of a triangle or a rectangle interactively 
and display the area. Remember the two values given as 
input will be treated as lengths of two sides in the case of 
rectangles and as base and height in the case of triangle 
and used as follows: 
Area of rectangle = x * y 
Area of triangle = 1/2 *x*y */
#include <iostream>
using namespace std;
class shape {
protected:
    double x, y;
public:
    void get_data() {
        cout << "Enter two values: ";
        cin >> x >> y;
    }
    virtual void display_area() {
        cout << "Base shape area (not defined)\n";
    }
    virtual ~shape() = default;
};

class rectangle : public shape {
public:
    void display_area() override {
        cout << "Area of rectangle = " << (x * y) << '\n';
    }
};

class triangle : public shape {
public:
    void display_area() override {
        cout << "Area of triangle = " << (0.5 * x * y) << '\n';
    }
};

int main() {
    cout << "1. Rectangle\n2. Triangle\n3. Exit\nChoose: ";
    int ch; 
    cin >> ch;
    if (ch == 1) {
        rectangle r;
        r.get_data();
        r.display_area();
    } else {
        triangle t;
        t.get_data();
        t.display_area();
    }
}
