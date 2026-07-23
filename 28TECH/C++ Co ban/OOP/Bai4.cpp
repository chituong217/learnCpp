#include <bits/stdc++.h>

using namespace std;

class NV{
private:
    string manv, hoten;
    string gioitinh;
    string ngaysinh, diachi, masothue, ngaykihd;
public:
    friend istream& operator >> (istream &in, NV &x){
        getline(in, x.hoten);
        getline(in, x.gioitinh);
        getline(in, x.ngaysinh);
        getline(in, x.diachi);
        getline(in, x.masothue);
        getline(in, x.ngaykihd);
        return in;
    }
    friend ostream& operator << (ostream &out, NV x){
        out << x.manv << " " << x.hoten << " " << x.gioitinh << " " << x.ngaysinh << " " << x.diachi << " " << x.masothue << " " << x.ngaykihd << endl;
        return out;
    }
    void setMaNV(string manv);
};

void NV::setMaNV(string manv){
    this->manv = manv;
}

int main(){
    NV x;
    cin >> x;
    x.setMaNV("00001");
    cout << x;

    return 0;
}