#include <bits/stdc++.h>

using namespace std;

class Employee{
private:
    string name;
    int id;
    double baseSalary;
public:
    Employee(string name, int id, double baseSalary);
    string getName();
    int getID();
    double getBaseSalary();
};

Employee::Employee(string name, int id, double baseSalary){
    this->name = name;
    this->id = id;
    this->baseSalary = baseSalary;
}

string Employee::getName(){
    return name;
}

int Employee::getID(){
    return id;
}

double Employee::getBaseSalary(){
    return baseSalary;
}

#include "main.h"