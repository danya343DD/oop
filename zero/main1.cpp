#include <iostream>
#include "BankAccount.h"

using namespace std;

int main() {
    try {
        BankAccount acc1("Alice", -50.0);
    }
    catch (const invalid_argument& e) {
        cout << e.what() << "\n";
    }

    try {
        BankAccount acc2("Bob", 100.0);
        acc2.withdraw(-10.0);
    }
    catch (const invalid_argument& e) {
        cout << e.what() << "\n";
    }

    try {
        BankAccount acc3("Charlie", 50.0);
        acc3.withdraw(100.0);
    }
    catch (const runtime_error& e) {
        cout << e.what() << "\n";
    }

    return 0;
}