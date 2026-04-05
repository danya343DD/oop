#include <iostream>
#include <chrono>
#include "Thread.h"

using namespace std;

void fastTask() {
    cout << "Fast task started\n";
    cout << "Fast task finished\n";
}

void delayedTask() {
    cout << "Delayed task started\n";
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Delayed task finished\n";
}

int main() {
    ThreadGuard t1(fastTask);
    ThreadGuard t2(delayedTask);

    return 0;
}