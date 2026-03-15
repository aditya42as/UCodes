/*Practical No.9
Construct a Program in C++ to show the working of function overloading (compile time 
polymorphism) by using a function named calculate Area () to calculate area of square, 
rectangle and triangle using different signatures as required. 

Name: Aditya Singh
Section: E1
Roll no. 8*/

#include <iostream>
using namespace std;

class Area {
public:
    int calculateArea(int side) { 
        return side * side; 
    }
    int calculateArea(int l, int b) { 
        return l * b; 
    }
    float calculateArea(float b, float h) { 
        return 0.5 * b * h; 
    }
};
int main() {
    Area a;
    cout << "Square Area: " << a.calculateArea(5) << endl;
    cout << "Rectangle Area: " << a.calculateArea(4, 6) << endl;
    cout << "Triangle Area: " << a.calculateArea(4.0f, 5.0f);
    return 0;
}
