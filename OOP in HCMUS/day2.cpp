/*
Copy constructor
Assignment operator
Destructor


Bộ ba này cần cài đặt chung khi gặp các Member Data cần cấp phát bộ nhớ động
nếu không sẽ dẫn đến Memory leaked

Copy != Assignmen ở chỗ:
Assignment nếu như thằng destination đang trỏ vào 1 vùng nhớ != NULL thì cần phải giải phóng nó trước
*/


#include <bits/stdc++.h>

using namespace std;

int ucln(int a, int b){
    a = abs(a);
    b = abs(b);
    while (b){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

class PhanSo{
private:
    int tuso, mauso;
public:
    PhanSo(){
        tuso = 0;
        mauso = 1;
    }

    PhanSo(int tuso1, int mauso1) : tuso(tuso1), mauso(mauso1){
        RutGon();
    }

    void RutGon(){
        // vo dinh
        if (mauso == 0){
            return;
        }

        if (tuso == 0){
            mauso = 1;
            return;
        }

        // rut gon
        int uc = ucln(tuso, mauso);
        tuso /= uc;
        mauso /= uc;

        // kiem tra am 
        if (mauso < 0){
            mauso *= -1;
            tuso *= -1;
        }
    }
    PhanSo operator + (const PhanSo& khac) const{
        PhanSo moi;
        moi.tuso = this->tuso * khac.mauso + khac.tuso * this->mauso;
        moi.mauso = this->mauso * khac.mauso;
        moi.RutGon();

        return moi;
    }
    PhanSo operator + (const int &so) const{
        PhanSo khac;
        khac.tuso = so;
        khac.mauso = 1;

        PhanSo moi;
        moi.tuso = this->tuso * khac.mauso + khac.tuso * this->mauso;
        moi.mauso = this->mauso * khac.mauso;
        moi.RutGon();

        return moi;
    }
    PhanSo operator - (const PhanSo& khac) const{
        PhanSo moi;
        moi.tuso = this->tuso * khac.mauso - khac.tuso * this->mauso;
        moi.mauso = this->mauso * khac.mauso;
        moi.RutGon();

        return moi;
    }
    PhanSo operator * (const PhanSo& khac) const{
        PhanSo moi;
        moi.tuso = this->tuso * khac.tuso;
        moi.mauso = this->mauso * khac.mauso;
        moi.RutGon();

        return moi;
    }

    bool operator < (const PhanSo& khac) const{
        if (this->mauso == khac.mauso){
            return this->tuso < khac.tuso;
        }
        else{
            int tu1 = this->tuso * khac.mauso;
            int tu2 = khac.tuso * this->mauso;

            return tu1 < tu2;
        }
    }
    bool operator > (const PhanSo& khac) const{
        if (this->mauso == khac.mauso){
            return this->tuso > khac.tuso;
        }
        else{
            int tu1 = this->tuso * khac.mauso;
            int tu2 = khac.tuso * this->mauso;

            return tu1 > tu2;
        }
    }
    bool operator == (const PhanSo& khac) const{
        if (this->mauso == khac.mauso){
            return this->tuso == khac.tuso;
        }
        else{
            return false;
        }
    }

    friend istream& operator >> (istream &in, PhanSo &x){
        in >> x.tuso >> x.mauso;
        x.RutGon();
        return in;
    }
    friend ostream& operator << (ostream &out, const PhanSo &x){
        out << x.tuso << '/' << x.mauso;
        return out;
    }
};

int main(){

    return 0;
}