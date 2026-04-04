#include <iostream>
#include "SafeDivision.h"
#include "ZeroExcept.h"

using namespace std;

int main() {
    try {
        cout << SafeDivision::divide(10.0, 2.0) << "\n";
        cout << SafeDivision::divide(5.0, 0.0) << "\n";
    }
    catch (const ZeroExcept& e) {
        cout << e.what() << "\n";
    }
    return 0;
}