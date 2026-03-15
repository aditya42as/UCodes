#include <iostream>
using namespace std;

class lowBalance_exception: public exception{
    public:
        const char* what() const noexcept{
            return "Insufficient Balance(withdrawn amount is greater than left balance)";
        }
};

class bank{
    double balance;
    public:
        bank(double balance) {
            this->balance = balance;
        }
        void deposit(double amount) {
            balance = balance + amount;
            cout << "New Balance: "<< balance << endl; 
        }
        void withdrawl(double amount){
            
            try{
                if(amount > balance) {
                    throw lowBalance_exception();
                }
                else{
                    balance = balance - amount;
                    cout << "Amount Withdrawn: " << amount << endl;
                    cout << "New Balance: " << balance << endl;
                }
            }
            catch(const lowBalance_exception& e) {
                cout << e.what();
            }

            cout << "\nNORMAL FLOW\n";
        }
};


int main() {
    bank b1(0.0);
    int deposit, withdraw;

    cout << "Enter the amount to deposit in the bank: ";
    cin >> deposit;
    b1.deposit(deposit);

    cout << "Enter the amount to withdraw from the bank: ";
    cin >> withdraw;
    b1.withdrawl(withdraw);

}