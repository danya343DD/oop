#pragma once
#include <string>
#include <iostream>

using namespace std;

class Book {
private:
    string author;
    string title;
    string publisher;
    int year;
    int quantity;
    int pages;

public:
    explicit Book(const string& author,
        const string& title,
        const string& publisher,
        int year,
        int quantity,
        int pages);

    string getAuthor() const;
    string getTitle() const;
    string getPublisher() const;
    int getYear() const;
    int getQuantity() const;
    int getPages() const;

    void display() const;

    ~Book();
};


