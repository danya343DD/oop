#pragma once
#include <chrono>

using namespace std;

class Timer {
    chrono::time_point<chrono::high_resolution_clock> start;
public:
    Timer();
    ~Timer();
};

