/*You are given three classes A, B and C. All three classes 
implement their own version of func. In class A, func 
multiplies the value passed as a parameter by 2. In class 
B, func multiplies the value passed as a parameter by 3. In 
class C, func multiplies the value passed as a parameter by 
5.You are given class D such that You need to modify the 
class D and implement the function update_val which sets 
October 08, 2025 October 11, 2025 
D's val to new_val by manipulating the value by only 
calling the func defined in classes A, B and C.It is 
guaranteed that new_val has only 2, 3 and 5 as its prime 
factors. Implement class D's function update_val. This 
function should update D's val only by calling A, B and 
C's func. */
#include <iostream>
using namespace std;

class A {
public:
    void func(int &val) {
        val *= 2;
    }
};
class B {
public:
    void func(int &val) {
        val *= 3;
    }
};
class C {
public:
    void func(int &val) {
        val *= 5;
    }
};

class D {
    int val;
public:
    D() { 
        val = 1;
    }
    void update_val(int new_val) {
        A a;
        B b;
        C c;
        while (new_val % 2 == 0) {
            a.func(val);
            new_val /= 2;
        }
        while (new_val % 3 == 0) {
            b.func(val);
            new_val /= 3;
        }
        while (new_val % 5 == 0) {
            c.func(val);
            new_val /= 5;
        }
    }
    void show() { 
        cout << val << endl; 
    }
};

int main() {
    D d;
    d.update_val(30); 
    d.show();
 
}
