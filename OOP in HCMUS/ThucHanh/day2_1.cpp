#include <bits/stdc++.h>

using namespace std;

class Device{
private:
    string name, model;
    int year;
    double cost;
public:
    Device(string name, string model, int year, double cost);
    string getName();
    string getModel();
    int getYear();
    double getCost();
};

Device::Device(string name, string model, int year, double cost){
    this->name = name;
    this->model = model;
    this->year = year;
    this->cost = cost;
}

string Device::getName(){
    return name;
}

string Device::getModel(){
    return model;
}

int Device::getYear(){
    return year;
}

double Device::getCost(){
    return cost;
}

#include "main.h"
// int main(){

//     return 0;
// }