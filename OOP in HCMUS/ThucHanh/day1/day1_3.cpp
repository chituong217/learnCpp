#include <bits/stdc++.h>

using namespace std;

class Product{
private:
    string name;
    double price;
    int quantity;
public:
    Product(string name, double price, int quantity);
    string getName();
    double getPrice();
    int getQuantity();
    double getTotalValue();
    void display();
};

Product::Product(string name, double price, int quantity){
    this->name = name;
    this->price = price;
    this->quantity = quantity;
}

string Product::getName(){
    return name;
}

double Product::getPrice(){
    return price;
}

int Product::getQuantity(){
    return quantity;
}

double Product::getTotalValue(){
    return price * quantity;
}

void Product::display(){
    cout << name << " - " << price << " - " << quantity << " - Total: " << fixed << setprecision(2) << getTotalValue() << endl;
}

#include "main.h"

// int main(){
//     Product* p1 = new Product("Laptop", 999.99, 3);
//     Product* p2 = new Product("Mouse", 25.50, 10);
//     p1->display();
//     p2->display();

//     return 0;
// }