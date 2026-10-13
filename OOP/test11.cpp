#include <bits/stdc++.h>

using namespace std;

class MangDong{
private:
    int* a;
    int n;
public:
    MangDong();
    MangDong(int size);
    ~MangDong();
    void Nhap();
    void Xuat() const;
    void ThemPhanTu(int val);
};

MangDong::MangDong(){
    a = nullptr;
    n = 0;
}

MangDong::MangDong(int size) : a(nullptr), n(size){
    if (n > 0){
        a = new int[n];
        for (int i = 0; i < n; i++){
            a[i] = 0;
        }
    }
    else{
        n = 0;
    }
}

MangDong::~MangDong(){
    if (a != nullptr){
        delete []a;
        a = nullptr;
    }
    n = 0;
    cout << "Da giai phong bo nho mang dong!";
}

void MangDong::Nhap(){
    cin >> n;
    if (a != nullptr){
        delete []a;
    }
    a = new int[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
}

void MangDong::Xuat() const{
    if (n == 0 || a == nullptr){
        cout << "Mang rong!";
    } 
    else{
        for (int i = 0; i < n; i++){
            cout << a[i] << ' ';
        }
        cout << endl;
    }
}

void MangDong::ThemPhanTu(int val){
    int* temp = new int[n + 1];
    for (int i = 0; i < n; i++){
        temp[i] = a[i];
    }
    temp[n] = val;
    delete []a;
    a = temp;
    n++;
}

int main(){

    return 0;
}