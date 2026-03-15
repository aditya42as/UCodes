/*Create a Base class that consists of private, protected and 
public data members and member functions. Try using 
different access modifiers for inheriting Base class to the 
Derived class and create a table that summarizes the 
above three modes (when derived in public, protected and 
private modes) and shows the access specifier of the 
members of base class in the Derived class. */

#include <iostream>
using namespace std;
class Base {
private:
    int a = 5;

protected:
    int b = 2;

public:
    int c = 3;
};
class Pub : public Base {
public:
    void show() {
        cout << "b: " << b << ", c: " << c << endl;
    }
};
class Protect : protected Base {
public:
    void show() {
        cout << "b: " << b << ", c: " << c << endl;
    }
};
class Private : private Base {
public:
    void show() {
        cout << "b: " << b << ", c: " << c << endl;
    }
};

int main() {
    Pub dp;
    dp.show();
    Protect dpr;
    dpr.show();
    Private dpri;
    dpri.show();
    
}
