#include <bits/stdc++.h>

using namespace std;

// inheritance

class Person{
private:
    string ten, diachi;
public:
    string getTen(){
        return ten;
    }
    string getDiaChi(){
        return diachi;
    }
    void setTen(string ten){
        this->ten = ten;
    }
    void setDiaChi(string diachi){
        this->diachi = diachi;
    }

    void inthongtin(){
        cout << ten << " " << diachi << ' ';
    }
};

class Student : public Person{
private:
    double gpa;
public:
    double getGPA(){
        return gpa;
    }
    void setGPA(double gpa){
        this->gpa = gpa;
    }

    void inthongtin(){
        Person::inthongtin();
        cout << fixed << setprecision(2) << gpa << endl;
    }
};

int main(){
    Student x;
    x.setTen("Le Xuan Han");
    x.setDiaChi("Tay Ninh");
    x.setGPA(3.6);

    x.inthongtin();

    return 0;
}