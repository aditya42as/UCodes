/*Practical No.16
Using the concept of operator overloading. Implement a program to overload 
the following: 
With the help of friend function 
a. Unary – 
b. Unary ++ preincrement, postincrement 
c. Unary -- predecrement, postdecrement */
#include <iostream>
using namespace std;
class Number {
    int value;
public:
    Number(int value) {
        this->value = value;
    }
    void display() {
        cout << value << endl;
    }
    friend void operator-(Number &num);
    friend void operator++(Number &num);
    friend void operator++(Number &num, int);
    friend void operator--(Number &num);
    friend void operator--(Number &num, int);
};
void operator-(Number &num) {
    num.value = -num.value;
}
void operator++(Number &num) {
    ++num.value;
}
void operator++(Number &num, int) {
    num.value++;
}
void operator--(Number &num) {
    --num.value;
}
void operator--(Number &num, int) {
    num.value--;
}
int main() {
    Number n(8);
    cout << "Value: ";
    n.display();
    cout << "Pre-increment: ";
    ++n;
    n.display();
    cout << "Post-increment: ";
    n++;
    n.display();
    cout << "Pre-decrement: ";
    --n;
    n.display();
    cout << "Post-decrement: ";
    n--;
    n.display();
    cout << "Unary minus: ";
    -n;
    n.display();
}
