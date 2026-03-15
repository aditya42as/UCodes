/*Practical No.13
Create class SavingsAccount. Use a static variable annualInterestRate to store the annual 
interest rate for all account holders. Each object of the class contains a private instance 
variable savingsBalance indicating the amount the saver currently has on deposit. 
Provide method calculateMonthlyInterest() to calculate the monthly interest by 
multiplying the savingsBalance by annualInterestRate divided by 12.This interest should 
be added to savingsBalance.  
Provide a static method modifyInterestRate() that sets the annualInterestRate to a new 
value. Write a program to test class SavingsAccount. Instantiate two savings Account 
objects, saver1 and saver2, with balances of Rs2000.00 and Rs3000.00, respectively. Set 
annualInterestRate to 4%, then calculate the monthly interest and print the new balances 
for both savers. Then set the annualInterestRate to 5%, calculate the next month’s 
interest and print the new balances for both savers*/
#include <iostream>
using namespace std;
class SavingsAccount {
private:
    float savingsBalance;
    static float annualInterestRate;
public:
    SavingsAccount() {
        savingsBalance = 0.0;
    }
    SavingsAccount(float balance = 0.0) {
        savingsBalance = balance;
    }
    void calculateMonthlyInterest() {
        float interest = (savingsBalance * annualInterestRate) / 12.0;
        savingsBalance += interest;
    }
    void display() {
        cout << "Balance: " << savingsBalance << endl;
    }
    static void modifyInterestRate(float newrate) {
        annualInterestRate = newrate;
    }
};
float SavingsAccount::annualInterestRate = 0.0;
int main() {
    SavingsAccount saver1(2000.0), saver2(3000.0);
    SavingsAccount::modifyInterestRate(0.04);  
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();
    cout << "After applying 4 percent annual interest :" << endl;
    cout << "Saver1 "; saver1.display();
    cout << "Saver2 "; saver2.display();
    SavingsAccount::modifyInterestRate(0.05);  
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();
    cout << "\nAfter applying 5 percent annual interest for next month:" << endl;
    cout << "Saver1 "; saver1.display();
    cout << "Saver2 "; saver2.display();
}
