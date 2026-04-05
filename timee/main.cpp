#include <iostream>
#include <memory>
#include <thread>
#include "Time.h"

using namespace std;

unique_ptr<Timer> createTimer() {
    return make_unique<Timer>();
}

int main() {
    {
        unique_ptr<Timer> t = createTimer();
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    return 0;
}