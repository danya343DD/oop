#pragma once
#include <cstddef>

template <typename T>
class Stack {
private:
    T* arr;
    size_t cap;
    size_t top_idx;

    void resize() {
        size_t new_cap = cap * 2;
        T* new_arr = new T[new_cap];
        for (size_t i = 0; i < top_idx; ++i) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        cap = new_cap;
    }

public:
    Stack(size_t c = 10) : cap(c), top_idx(0) {
        arr = new T[cap];
    }

    ~Stack() {
        delete[] arr;
    }

    Stack(const Stack& other) : cap(other.cap), top_idx(other.top_idx) {
        arr = new T[cap];
        for (size_t i = 0; i < top_idx; ++i) {
            arr[i] = other.arr[i];
        }
    }

    Stack& operator=(const Stack& other) {
        if (this != &other) {
            delete[] arr;
            cap = other.cap;
            top_idx = other.top_idx;
            arr = new T[cap];
            for (size_t i = 0; i < top_idx; ++i) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    void push(const T& value) {
        if (top_idx == cap) {
            resize();
        }
        arr[top_idx++] = value;
    }

    void pop() {
        if (top_idx > 0) {
            top_idx--;
        }
    }

    T& top() {
        return arr[top_idx - 1];
    }

    bool empty() const {
        return top_idx == 0;
    }

    size_t size() const {
        return top_idx;
    }
};

