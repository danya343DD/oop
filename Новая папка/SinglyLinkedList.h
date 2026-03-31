#pragma once
#include <cstddef>

template <typename T>
class SinglyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& v) : data(v), next(nullptr) {}
    };

    Node* head;
    size_t sz;

public:
    SinglyLinkedList() : head(nullptr), sz(0) {}

    ~SinglyLinkedList() {
        clear();
    }

    SinglyLinkedList(const SinglyLinkedList&) = delete;
    SinglyLinkedList& operator=(const SinglyLinkedList&) = delete;

    void push_front(const T& value) {
        Node* n = new Node(value);
        n->next = head;
        head = n;
        sz++;
    }

    void push_back(const T& value) {
        Node* n = new Node(value);
        if (!head) {
            head = n;
        }
        else {
            Node* cur = head;
            while (cur->next) {
                cur = cur->next;
            }
            cur->next = n;
        }
        sz++;
    }

    void pop_front() {
        if (head) {
            Node* t = head;
            head = head->next;
            delete t;
            sz--;
        }
    }

    void pop_back() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            sz--;
            return;
        }
        Node* cur = head;
        while (cur->next->next) {
            cur = cur->next;
        }
        delete cur->next;
        cur->next = nullptr;
        sz--;
    }

    T& front() {
        return head->data;
    }

    T& back() {
        Node* cur = head;
        while (cur->next) {
            cur = cur->next;
        }
        return cur->data;
    }

    bool empty() const {
        return sz == 0;
    }

    size_t size() const {
        return sz;
    }

    void clear() {
        while (head) {
            Node* t = head;
            head = head->next;
            delete t;
        }
        sz = 0;
    }
};