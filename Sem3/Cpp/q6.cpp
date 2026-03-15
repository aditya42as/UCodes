/*Practical No.6
Define a class Hotel in C++ with the following specifications. 
Private members 
• Rno Data member to store room number 
• Name Data member to store customer name 
• Tariff Data member to store per day charges 
• NOD Data member to store number of days of stay 
• CALC() Function to calculate and return amount as NOD*Tariff ,and if the 
value of days* Tariff >10000, 
then total amount is 1.05* days*Tariff. 
Public members 
• Checkin() Function to enter the content Rno, Name, Tariff and NOD 
• Checkout() Function to display Rno, Name, Tariff, 
NOD and Amount (amount to be displayed by calling function) CALC() 

Name: Aditya Singh
Section: E1
Roll no. 8 */

#include <iostream>
using namespace std;
class Hotel {
private:
    int Rno, NOD;
    char Name[50];
    float Tariff;
    float CALC() {
        float amt = Tariff * NOD;
        if (amt > 10000)
            amt = amt + amt * 0.05;
        return amt;
    }
public:
    void Checkin() {
        cout << "Enter Room No: "; cin >> Rno;
        cout << "Enter Name: "; cin >> Name;
        cout << "Enter Tariff per day: "; cin >> Tariff;
        cout << "Enter No of Days: "; cin >> NOD;
    }
    void Checkout() {
        cout << "\nRoom No: " << Rno;
        cout << "\nName: " << Name;
        cout << "\nTariff: " << Tariff;
        cout << "\nDays: " << NOD;
        cout << "\nAmount = Rs " << CALC();
    }
};
int main() {
    Hotel h;
    h.Checkin();
    h.Checkout();
}
