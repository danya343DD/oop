#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
double getAverage(T arr[], int size) {
    if (size <= 0) return 0.0;
    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum / size;
}

template <typename T>
void findRoots(T a, T b) {
    if (a == 0) {
        if (b == 0) cout << "Infinite roots" << endl;
        else cout << "No roots" << endl;
    }
    else {
        cout << "x = " << (double)-b / a << endl;
    }
}

template <typename T>
void findRoots(T a, T b, T c) {
    if (a == 0) {
        findRoots(b, c);
        return;
    }
    double d = b * b - 4 * a * c;
    if (d > 0) {
        cout << "x1 = " << (-b + sqrt(d)) / (2 * a) << ", x2 = " << (-b - sqrt(d)) / (2 * a) << endl;
    }
    else if (d == 0) {
        cout << "x = " << -b / (2 * a) << endl;
    }
    else {
        cout << "No real roots" << endl;
    }
}

template <typename T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}

template <typename T>
T getMin(T a, T b) {
    return (a < b) ? a : b;
}


