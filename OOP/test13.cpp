#include <bits/stdc++.h>

using namespace std;

class SoPhuc{
private:
    float thuc, ao;
public:
    SoPhuc();
    SoPhuc(float t, float a);
    SoPhuc operator + (const SoPhuc& p2) const;
    SoPhuc operator - (const SoPhuc& p2) const;
    SoPhuc operator * (const SoPhuc& p2) const;
    bool operator == (const SoPhuc& p2) const;
    bool operator != (const SoPhuc& p2) const;
    void Xuat() const;
};

SoPhuc::SoPhuc() : thuc(0), ao(0){
    
}

SoPhuc::SoPhuc(float t, float a) : thuc(t), ao(a){

}

SoPhuc SoPhuc::operator + (const SoPhuc& p2) const{
    SoPhuc moi;
    moi.thuc = this->thuc + p2.thuc;
    moi.ao = this->ao + p2.ao;
    return moi;
}

SoPhuc SoPhuc::operator - (const SoPhuc& p2) const{
    SoPhuc moi;
    moi.thuc = this->thuc - p2.thuc;
    moi.ao = this->ao - p2.ao;
    return moi;
}

SoPhuc SoPhuc::operator * (const SoPhuc& p2) const{
    SoPhuc moi;
    moi.thuc = this->thuc * p2.thuc - this->ao * p2.ao;
    moi.ao = this->thuc * p2.ao + this->ao * p2.thuc;
    return moi;
}

bool SoPhuc::operator == (const SoPhuc& p2) const{
    if (this->thuc == p2.thuc && this->ao == p2.ao){
        return true;
    }
    return false;
}

bool SoPhuc::operator != (const SoPhuc& p2) const{
    return (*this) == p2;
}

void SoPhuc::Xuat() const{
    if (ao > 0){
        cout << thuc << " + " << ao << "i\n";
    }
    else if (ao < 0){
        cout << thuc << " - " << -ao << "i\n";
    }
    else{
        cout << thuc << "\n";
    }
}

int main(){

    return 0;
}