/*Practical No.1
An electricity board charges the following rates to domestic users to discourage large 
consumption of energy. 
For the first 100 units: - 60 P per unit 
For the next 200 units: -80 P per unit 
Beyond 300 units: -90 P per unit 
All users are charged a minimum of Rs 50 if the total amount is more than Rs 300 then 
an additional surcharge of 15% is added. 
Implement a C++ program to read the names of users and number of units consumed and 
display the charges with names.

Name: Aditya Singh
Section: E1*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    int units;
    cout << "Enter customer name: ";
    getline(cin, name);
    cout << "Enter units consumed: ";
    cin >> units;

    float amount = 50;
    if (units <= 100)
        amount += units * 0.60;
    else if (units <= 300)
        amount += (100 * 0.60) + (units - 100) * 0.80;
    else
        amount += (100 * 0.60) + (200 * 0.80) + (units - 300) * 0.90;

    if (amount > 300)
        amount += amount * 0.15;

    cout << "Customer: " << name << endl;
    cout << "Units: " << units << endl;
    cout << "Bill Amount: Rs " << amount;
    
}
