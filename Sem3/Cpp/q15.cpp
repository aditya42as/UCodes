/*Practical No.15
Using the concept of operator overloading. Implement a program to overload the 
following: 
a. Unary – 
b. Unary ++ preincrement, postincrement 
c. Unary -- predecrement, postdecrement */

#include <iostream>
using namespace std;
class Number {
    int value;
public:
    Number(int v = 0) {
        value = v;
    }
    void operator-() {
       value = -value;
    }
    void operator++() {
        ++value;
    }
    void operator++(int) {
        value++;
    }
    void operator--() {
        --value;
    }
    void operator--(int) {
        value--;
    }
    void display() {
        cout << value << endl;
    }
};
int main() {
    Number n(10);
    cout << "Value: ";
    n.display();
    cout << "Pre-increment: ";
    ++n;
    n.display();
    cout << "Post-increment: ";
    n++;
    n.display();
    cout << "After post-increment: ";
    n.display();
    cout << "Pre-decrement: ";
    --n;
    n.display();
    cout << "Post-decrement: ";
    n--;
    n.display();
    cout << "After post-decrement: ";
    n.display();
    cout<< "Unary minus: ";
    -n;
    n.display();

}
