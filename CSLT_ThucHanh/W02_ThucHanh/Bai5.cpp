#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double gpa;
    cout << "Nhap vao diem trung binh cua sinh vien:";
    cin >> gpa;
    if (gpa >= 9 && gpa <=10){
        cout<<"Xep loai xuat sac"<< endl;
    }
    else if (gpa >= 8 && gpa <9){
        cout<<"Xep loai gioi"<< endl;
    }
    else if (gpa <8 && gpa >=7){
        cout << "Xep loai kha"<< endl;
    }
    else if ( gpa <7 && gpa >=6){
        cout << "Xep loai trung binh kha" << endl;
    }
    else if (gpa <6 && gpa >=5){
        cout << "Xep loai trung binh" << endl;
    }
    else if (gpa <5 && gpa >=4){
        cout << "Xep loai yeu" << endl;
    }
    else if (gpa <4){
        cout << "Xep loai kem" << endl;
    }
    return 0;
}