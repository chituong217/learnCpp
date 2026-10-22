#include "day2_5.h"


Employee::Employee(){
    fullName = "";
    employeeID = "";
    age = 0;
    department = "";
    salary = 0;
}

Employee::Employee(string name, string id, int age, string department, float salary){
    this->fullName = name;
    this->employeeID = id;
    this->age = age;
    this->department = department;
    this->salary = salary;
}

void Employee::displayInfo(){
    cout << "Name: " << fullName << endl;
    cout << "Employee ID: " << employeeID << endl;
    cout << "Age: " << age << endl;
    cout << "Department: " << department << endl;
    cout << "Salary: " << fixed << setprecision(2) << salary << endl;
}

string Employee::getFullName(){
    return fullName;
}

void Employee::setFullName(string name){
    this->fullName = name;
}

string Employee::getEmployeeID(){
    return employeeID;
}

void Employee::setEmployeeID(string id){
    this->employeeID = id;
}

int Employee::getAge(){
    return age;
}

void Employee::setAge(int age){
    this->age = age;
}

string Employee::getDepartment(){
    return department;
}

void Employee::setDepartment(string department){
    this->department = department;
}

float Employee::getSalary(){
    return salary;
}

void Employee::setSalary(float salary){
    this->salary = salary;
}


void EmployeeManager::addEmployee(const Employee& employee){
    employees.push_back(employee);
}

void EmployeeManager::removeEmployee(const std::string& employeeID){
    for (auto it = employees.begin(); it != employees.end(); ++it){
        if (it->getEmployeeID() == employeeID){
            employees.erase(it);
            return;
        }
    }
}

void EmployeeManager::displayAllEmployees(){
    for (int i = 0; i < (int)employees.size(); i++){
        employees[i].displayInfo();

        if (i < (int) employees.size() - 1){
            cout << "==============================" << endl;
        }
    }
}

Employee EmployeeManager::findEmployeeByID(const std::string& employeeID){
    for (Employee x : employees){
        if (x.getEmployeeID() == employeeID){
            return x;
        }
    }
    Employee x;
    return x;
}