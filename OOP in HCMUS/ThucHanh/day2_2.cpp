#include <bits/stdc++.h>

using namespace std;

class Book{
private:
    string title, author, ISBN;
    bool available;
public:
    Book();
    Book(string title, string author, string ISBN);

    string getTitle();
    void setTitle(string title);

    string getAuthor();
    void setAuthor(string author);

    string getISBN();
    void setISBN(string ISBN);

    bool isAvailable();
    void borrowBook();
    void returnBook();
    
    void displayBook();
};

Book::Book(){
    title = "";
    author = "";
    ISBN = "";
    available = false;
}

Book::Book(string title, string author, string ISBN){
    this->title = title;
    this->author = author;
    this->ISBN = ISBN;
    available = true;
}

string Book::getTitle(){
    return title;
}

void Book::setTitle(string title){
    this->title = title;
}

string Book::getAuthor(){
    return author;
}

void Book::setAuthor(string author){
    this->author = author;
}

string Book::getISBN(){
    return ISBN;
}

void Book::setISBN(string ISBN){
    this->ISBN = ISBN;
}

bool Book::isAvailable(){
    return available;
}

void Book::borrowBook(){
    available = false;
}

void Book::returnBook(){
    available = true;
}

void Book::displayBook(){
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "ISBN: " << ISBN << endl;
    cout << "Availability: ";
    if (available){
        cout << "Available" << endl;
    }
    else{
        cout << "Not available" << endl;
    }
}

// int main(){

//     return 0;
// }

#include "main.h"