#include "BankAccount.h"

using namespace std;

BankAccount::BankAccount(string n, double initialBalance) : name(n), balance(initialBalance) {
    if (balance < 0) {
        throw invalid_argument("Negative initial balance");
    }
}

void BankAccount::withdraw(double amount) {
    if (amount < 0) {
        throw invalid_argument("Negative withdrawal amount");
    }
    if (amount > balance) {
        throw runtime_error("Insufficient funds");
    }
    balance -= amount;
}

double BankAccount::getBalance() const {
    return balance;
}
