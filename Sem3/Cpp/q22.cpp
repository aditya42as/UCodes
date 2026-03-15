/*Create a base class called CAL_AREA(Abstract). Use this 
class to store float type values that could be used to 
compute the volume of figures. Derive two specific 
classes called cone, hemisphere and cylinder from the 
base CAL_AREA. Add to the base class, a member 
function getdata ( ) to initialize base class data members 
and another member function display volume( ) to 
compute and display the volume of figures. Make display 
volume ( ) as a pure virtual function and redefine this 
function in the derived classes to suit their requirements. 
Using these three classes, design a program that will 
accept dimensions of a cone, cylinder and hemisphere 
interactively and display the volumes. Remember values 
given as input will be and used as follows: 
Volume of cone = (1/3)πr2h 
Volume of hemisphere = (2/3)πr3 
Volume of cylinder = πr2h */

#include <iostream>
using namespace std;
class CAL_AREA {
protected:
    float r, h;
public:
    virtual void getdata() {
        cout << "Enter r and h: ";
        cin >> r >> h;
    }
    virtual void display_volume() const = 0; 
    virtual ~CAL_AREA() = default;
};

class Cone : public CAL_AREA {
public:
    void getdata() override {
        cout << "Enter radius r and height h for cone: ";
        cin >> r >> h;
    }
    void display_volume() const override {
        float PI = 3.14;
        float vol = (1.0 / 3.0) * PI * r * r * h;
        cout << "Volume of cone = " << vol << endl;
    }
};

class Hemisphere : public CAL_AREA {
public:
    void getdata() override {
        cout << "Enter radius r for hemisphere: ";
        cin >> r;
        h = 0.0;
    }
    void display_volume() const override {
        float PI = 3.14;
        float vol = (2.0 / 3.0) * PI * r * r * r;
        cout << "Volume of hemisphere = " << vol << endl;
    }
};

class Cylinder : public CAL_AREA {
public:
    void getdata() override {
        cout << "Enter radius r and height h for cylinder: ";
        cin >> r >> h;
    }
    void display_volume() const override {
        float PI = 3.14;
        float vol = PI * r * r * h;
        cout << "Volume of cylinder = " << vol << endl;
    }
};

int main() {
    int choice;
     cout << "\n1. Cone\n2. Hemisphere\n3. Cylinder\n4. Exit\nChoose: ";
    do {
        cin >> choice;

        CAL_AREA* shape = nullptr;

        if (choice == 1) shape = new Cone();
        else if (choice == 2) shape = new Hemisphere();
        else if (choice == 3) shape = new Cylinder();
        else if (choice == 4) {
            cout << "Exiting..." << endl;
            break;
        } else {
            cout << "Invalid choice. Try again." << endl;
            continue;
        }

        shape->getdata();
        shape->display_volume();

        delete shape;
    } while (true);
}
