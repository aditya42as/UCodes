/*Practical No.11
Imagine a tollbooth with a class called TollBooth. The two data items are of type unsigned int and double to hold the total number of cars and total amount of money collected. A constructor initializes both of these data members to 0. A member function called payingCar( )increments the car total and adds 0.5 to the cash total. Another function called nonPayCar( ) increments the car total but adds nothing to the cash total. Finally a member function called display( )shows the two totals. Include a program to test this class.
*/

#include <iostream>
#include <conio.h>
using namespace std;

class TollBooth {
private:
    unsigned int carCount;
    double cashTotal;

public:
    TollBooth() {
        carCount = 0;
        cashTotal = 0.0;
    }

    void payingCar() {
        carCount++;
        cashTotal += 0.5;
    }

    void nonPayCar() {
        carCount++;
    }

    void display() {
        cout << "Total Cars: " << carCount << endl;
        cout << "Total Cash: Rs." << cashTotal << endl;
    }
};
int main() {
    TollBooth booth;
    char ch = 0;
    cout << "Press:\n'p' for Paying Car\n'n' for Non-Paying Car\n'esc' to Exit\n\n";
    while (ch != 27) {
        ch = _getch();
        if (ch == 27) {
            booth.display();
            break;
        }
        else if (ch == 'p' || ch == 'P') {
            booth.payingCar();
            cout << "Paying car counted\n";
        }
        else if (ch == 'n' || ch == 'N') {
            booth.nonPayCar();
            cout << "Non-paying car counted\n";
        }
        else {
            cout << "Invalid Input\n";
        }
    }
}
