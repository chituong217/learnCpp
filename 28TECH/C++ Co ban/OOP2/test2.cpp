#include <bits/stdc++.h>

using namespace std;

// polymorphism

class Hinh{
protected:
    int cao, rong;
public:
    void setValue(int cao, int rong){
        this->cao = cao;
        this->rong = rong;
    }
    // virtual member : con tro lop cha goi ham lop con
    virtual int getArea(){
        return 0;
    }
};

class HinhChuNhat : public Hinh{
public:
    int getArea(){
        return cao * rong;
    }
};

class HinhTamGiac : public Hinh{
public:
    int getArea(){
        return cao * rong / 2;
    }
};

int main(){
    HinhChuNhat a;
    HinhTamGiac b;

    Hinh *ptr1 = &a;
    Hinh *ptr2 = &b;

    ptr1->setValue(10, 5);
    ptr2->setValue(3, 14);

    cout << ptr1->getArea() << ' ' << ptr2->getArea();

    return 0;
}