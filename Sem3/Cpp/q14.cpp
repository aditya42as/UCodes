/*Create a class Complex having two int type variable named real & img denoting real and 
imaginary part respectively of a complex number. Overload +, - , == operator to add, to 
subtract and to compare two complex 
numbers being denoted by the two complex type objects*/

#include <iostream>
using namespace std;
class Complex {
    int real;
    int img;
public:
    Complex(int r = 0, int i = 0) {
        real = r;
        img = i;
    }
    void operator+(Complex& c) {
        Complex temp;
        temp.real = real + c.real;
        temp.img = img + c.img;
        cout << "Sum = ";
        temp.display();
        cout << endl;
    }
    void operator-(Complex& c) {
        Complex temp;
        temp.real = real - c.real;
        temp.img = img - c.img;
        cout << "Difference = ";
        temp.display();
        cout << endl;
    }
    void operator==(Complex& c) {
        if (real == c.real && img == c.img)
            cout << "Both complex numbers are equal" << endl;
        else
            cout << "Both complex numbers are not equal" << endl;
    }
    void display() {
        if (img >= 0)
            cout << real << " + " << img << "i";
        else
            cout << real << " - " << -img << "i";
    }
};
int main() {
    Complex c1(3, 4), c2(1, -2);
    cout << "c1 = "; c1.display(); cout << endl;
    cout << "c2 = "; c2.display(); cout << endl;
    c1 + c2;  
    c1 - c2;   
    c1 == c2;  
}
