/*Practical No.7
Implement a Program in C++ by defining a class to represent a bank account. Include the
following:
Data Members
• Name of the depositor
• Account number
• Type of account (Saving, Current etc.)
• Balance amount in the account
Member Functions
• To assign initial values
• To deposit an amount
• To withdraw an amount after checking the balance
• To display name and balance

Name: Aditya Singh
Section: E1
Roll no. 8*/

#include <iostream>
using namespace std;
class Bank {
    string name;
    int accNo;
    string type;
    double balance;
public:
    void assign(string n, int a, string t, double b) {
        name = n;
        accNo = a;
        type = t;
        balance = b;
    }
    void deposit(double amt) { 
        balance += amt;
    }
    void withdraw(double amt)
    {
        if (balance >= amt){
            balance -= amt;
        }
        else {
            cout << "Insufficient balance\n";
        }
    }
    void display(){
        cout << "Name: " << name <<endl<< "Balance: " << balance << endl;
    }
};
int main()
{
    Bank b;
    int dep,withdraw;
    b.assign("Aditya", 101, "Saving", 5000);
    cout << "Enter the amount to deposit: ";
    cin >> dep;
    cout<< "Enter the amount to wiithdraw: ";
    cin >> withdraw;
    b.deposit(dep);
    b.withdraw(withdraw);
    cout<< "Balance amount in the bank: "<< endl;
    b.display();
}
