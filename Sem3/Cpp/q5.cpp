/*Practical No.5
Implement a C++ program to demonstrate the concept of data abstraction using the 
concept of Class and Objects. 

Name: Aditya Singh
Section: E1
Roll no. 8*/

#include <iostream>
using namespace std;
class Account {
private:
    int balance;
public:
    Account(int b) { 
        balance = b; 
    }
    void deposit(int amt) { 
        balance += amt; 
    }
    void display() { 
        cout << "Balance: Rs " << balance; 
    }
};
int main() {
    int bal,dep;
    cout<< "Enter the balance amount in the account: ";
    cin >> bal;
    cout<< "Enter the amount you want to deposit: ";
    cin >> dep;
    Account a1(bal);
    a1.deposit(dep);
    a1.display();    
}
