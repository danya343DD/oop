#include "Time.h"
#include <iostream>

using namespace std;

Timer::Timer() {
    start = chrono::high_resolution_clock::now();
}

Timer::~Timer() {
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << duration.count() << "\n";
}
