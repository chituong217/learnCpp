#include <bits/stdc++.h>

using namespace std;

class WaitList{
private:
    int* mssv;
    int soLuong;
public:
    WaitList();
    WaitList(int capacity);
    ~WaitList();
    WaitList(const WaitList &other);
    WaitList& operator = (const WaitList &other);
    void Nhap();
    void Xuat() const;
};

WaitList::WaitList(){
    mssv = nullptr;
    soLuong = 0;
}

WaitList::WaitList(int capacity){
    if (capacity <= 0){
        mssv = nullptr;
        soLuong = 0;
    }
    else{
        mssv = new int[capacity];
        soLuong = capacity;
        for (int i = 0; i < capacity; i++){
            mssv[i] = 0;
        }
    }
}

WaitList::~WaitList(){
    if (mssv != nullptr){
        delete []mssv;
    }
    soLuong = 0;
    mssv = nullptr;
}

WaitList::WaitList(const WaitList &other){
    if (other.soLuong == 0 || other.mssv == nullptr){
        this->soLuong = 0;
        this->mssv = nullptr;
    }
    else{
        this->soLuong = other.soLuong;
        this->mssv = new int[this->soLuong];
        for (int i = 0; i < this->soLuong; i++){
            this->mssv[i] = other.mssv[i];
        }
    }
}

WaitList& WaitList::operator=(const WaitList &other){
    if (this == &other){
        return *this;
    }

    if (this->mssv != nullptr){
        delete []this->mssv;
    }

    if (other.soLuong == 0 || other.mssv == nullptr){
        this->soLuong = 0;
        this->mssv = nullptr;
        return;
    }

    this->soLuong = other.soLuong;
    this->mssv = new int[this->soLuong];
    for (int i = 0; i < this->soLuong; i++){
        this->mssv[i] = other.mssv[i];
    }

    return *this;
}

void WaitList::Nhap(){
    do{
        cin >> soLuong;
    }
    while(soLuong <= 0);
    if (this->mssv != nullptr){
        delete []this->mssv;
    }
    this->mssv = new int[soLuong];
    for (int i = 0; i < soLuong; i++){
        cin >> mssv[i];
    }
}

void WaitList::Xuat() const{
    if (soLuong == 0 || mssv == nullptr){
        cout << "Danh sach rong!" << endl;
        return;
    }
    for (int i = 0; i < soLuong; i++){
        cout << this->mssv[i] << ' ';
    }
}

int main(){

    return 0;
}