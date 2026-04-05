#pragma once
#include <thread>
#include <utility>

using namespace std;

class ThreadGuard {
    thread t;
public:
    template<typename Callable, typename... Args>
    ThreadGuard(Callable&& f, Args&&... args) : t(forward<Callable>(f), forward<Args>(args)...) {}

    ~ThreadGuard() {
        if (t.joinable()) {
            t.join();
        }
    }

    ThreadGuard(const ThreadGuard&) = delete;
    ThreadGuard& operator=(const ThreadGuard&) = delete;
};
