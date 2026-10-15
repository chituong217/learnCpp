#include <bits/stdc++.h>

using namespace std;

class Product{
private:
    string productName;
    int productID;
    float price;
    int quantity;
public:
    Product();
    Product(string name, int id, float price, int quantity);
    string getProductName();
    void setProductName(string name);
    int getProductID();
    void setProductID(int id);
    float getPrice();
    void setPrice(float price);
    int getQuantity();
    void setQuantity(int quantity);
    void printInfo();
};

Product::Product(){
    productName = "";
    productID = 0;
    price = 0;
    quantity = 0;
}

Product::Product(string name, int id, float price, int quantity){
    this->productName = name;
    this->productID = id;
    this->price = price;
    this->quantity = quantity;
}

string Product::getProductName(){
    return productName;
}

void Product::setProductName(string name){
    this->productName = name;
}

int Product::getProductID(){
    return productID;
}

void Product::setProductID(int id){
    this->productID = id;
}

float Product::getPrice(){
    return price;
}

void Product::setPrice(float price){
    this->price = price;
}

int Product::getQuantity(){
    return quantity;
}

void Product::setQuantity(int quantity){
    this->quantity = quantity;
}

void Product::printInfo(){
    cout << "Product Name: " << productName << endl;
    cout << "Product ID: " << productID << endl;
    cout << "Price: $" << fixed << setprecision(3) << price << endl;
    cout << "Quantity: " << quantity << endl;
    cout << endl;
}

#include "main.h"
// int main(){

//     return 0;
// }