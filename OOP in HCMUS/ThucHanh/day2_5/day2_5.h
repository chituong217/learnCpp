#ifndef EMPLOYEEMANAGER
#define EMPLOYEEMANAGER

#include <bits/stdc++.h>

using namespace std;


class Employee{
private:
    string fullName, employeeID;
    int age;
    string department;
    float salary;
public:
    Employee();
    Employee(string name, string id, int age, string department, float salary);
    
    void displayInfo();
    
    string getFullName();
    void setFullName(string name);
    
    string getEmployeeID();
    void setEmployeeID(string employeeID);

    int getAge();
    void setAge(int age);

    string getDepartment();
    void setDepartment(string department);

    float getSalary();
    void setSalary(float salary);
};


class EmployeeManager{
private:
    vector<Employee> employees;
public:
    void addEmployee(const Employee& employee);
    void removeEmployee(const std::string& employeeID);
    void displayAllEmployees();
    Employee findEmployeeByID(const std::string& employeeID);
};

#endif