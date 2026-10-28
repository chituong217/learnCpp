#include <bits/stdc++.h>

using namespace std;

class Person{
private:
    string id, name;
public:
    Person(){
        id = "";
        name = "";
    }
    Person(string ma, string ten) : id(ma), name(ten){

    }

    virtual void display () const{
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
    }

    virtual ~Person() = default;
};

class Student : public Person{
private:
    string major;
public:
    Student() : Person(){
        major = "";
    }
    Student(string ma, string ten, string maj) : Person(ma, ten), major(maj){

    }

    void display() const override{
        Person::display();
        cout << "Major: " << major << endl;
    }
};

int main(){
    Student x("25120465", "Nguyen Le Chi Tuong", "CNTT");
    x.display();
    return 0;
}