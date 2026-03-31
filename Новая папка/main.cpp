#include <iostream>
#include <string>
#include "SinglyLinkedList.h"
#include "Stack.h"
#include "Queue.h"

void testLinkedList() {
    SinglyLinkedList<int> intList;
    intList.push_front(1);
    intList.push_front(2);
    intList.push_back(3);
    intList.push_back(4);

    cout << "List size: " << intList.size() << std::endl;
    cout << "Front: " << intList.front() << std::endl;
    cout << "Back: " << intList.back() << std::endl;

    intList.pop_front();
    intList.pop_back();

    cout << "After pop front/back size: " << intList.size() << std::endl;

    SinglyLinkedList<std::string> strList;
    strList.push_front("Hello");
    strList.push_back("World");
    std::cout << "String List Front: " << strList.front() << std::endl;
    std::cout << "String List Back: " << strList.back() << std::endl;
    strList.clear();
    std::cout << "List empty: " << strList.empty() << std::endl;
}

void testStackPalindrome() {
    std::string input;
    std::cout << "Enter string for palindrome check: ";
    std::cin >> input;

    Stack<char> s;
    for (char c : input) {
        s.push(c);
    }

    bool isPalindrome = true;
    for (char c : input) {
        if (c != s.top()) {
            isPalindrome = false;
            break;
        }
        s.pop();
    }

    if (isPalindrome) {
        std::cout << "Palindrome" << std::endl;
    }
    else {
        std::cout << "Not Palindrome" << std::endl;
    }
}

void testQueueTasks() {
    Queue<int> taskQueue;
    taskQueue.enqueue(1);
    taskQueue.enqueue(2);
    taskQueue.enqueue(3);

    std::cout << "Processing tasks:" << std::endl;
    while (!taskQueue.empty()) {
        std::cout << "Task " << taskQueue.front() << " processed" << std::endl;
        taskQueue.dequeue();
    }
}

int main() {
    testLinkedList();
    testStackPalindrome();
    testQueueTasks();
    return 0;
}