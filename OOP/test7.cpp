// bai tap 1.2.2
#include <bits/stdc++.h>

using namespace std;

class SoPhuc{
private:
    float thuc, ao;
public:
    void Nhap();
    void Xuat() const;
    float TinhModule() const;
    SoPhuc Cong(const SoPhuc &p2) const;
    SoPhuc Nhan(const SoPhuc &p2) const;
};

void SoPhuc::Nhap(){
    cin >> thuc >> ao;
}

void SoPhuc::Xuat() const{
    if (ao > 0){
        cout << thuc << " + " << ao << "i\n";
    }
    else if (ao < 0){
        cout << thuc << " - " << -ao << "i\n";
    }
    else{
        cout << thuc << endl;
    }
}

float SoPhuc::TinhModule() const{
    return sqrt(pow(thuc, 2) + pow(ao, 2));
}

SoPhuc SoPhuc::Cong(const SoPhuc &p2) const{
    SoPhuc moi;
    moi.thuc = this->thuc + p2.thuc;
    moi.ao = this->ao + p2.ao;
    return moi;
}

SoPhuc SoPhuc::Nhan(const SoPhuc &p2) const{
    SoPhuc moi;
    moi.thuc = (this->thuc*p2.thuc - this->ao*p2.ao);
    moi.ao = (this->thuc*p2.ao + this->ao*p2.thuc);

    return moi;
}

int main(){

}