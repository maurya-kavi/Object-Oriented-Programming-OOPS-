#include<iostream>
#include<string>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount() {
        balance = 0;
    }

    void deposit(double amount) {
        if(amount > 0){
            balance += amount;
            cout<< "Deposited: $" << amount << endl;
        }
    }

    void withdraw(double amount) {
        if(amount > 0 && amount <= balance){
            balance -= amount;
            cout<< "Withdrawn: $" << amount << endl;
        }
    }

    double getBalance() const {
        return balance;
    }
};

int main(){
    
    BankAccount account;
    account.deposit(1000);
    account.withdraw(500);
    account.withdraw(-100);
    cout << "Current Balance: $" << account.getBalance() << endl;

    return 0;
}


//output
// Deposited: $1000
// Withdrawn: $500
// Current Balance: $500