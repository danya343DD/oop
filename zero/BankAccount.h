#pragma once
#include <string>
#include <stdexcept>

using namespace std;

class BankAccount {
    string name;
    double balance;
public:
    BankAccount(string n, double initialBalance);
    void withdraw(double amount);
    double getBalance() const;
};

