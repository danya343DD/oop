#include "Book.h"

Book::Book(const string& author,
    const string& title,
    const string& publisher,
    int year,
    int quantity,
    int pages)
    : author(author), title(title), publisher(publisher),
    year(year), quantity(quantity), pages(pages) {
}

string Book::getAuthor() const {
    return author;
}

string Book::getTitle() const {
    return title;
}

string Book::getPublisher() const {
    return publisher;
}

int Book::getYear() const {
    return year;
}

int Book::getQuantity() const {
    return quantity;
}

int Book::getPages() const {
    return pages;
}

void Book::display() const {
    cout << "Автор: " << author << endl;
    cout << "Название: " << title << endl;
    cout << "Издательство: " << publisher << endl;
    cout << "Год: " << year << endl;
    cout << "Количество: " << quantity << endl;
    cout << "Страниц: " << pages << endl;
    cout << "------------------------" << endl;
}

Book::~Book() {
}
