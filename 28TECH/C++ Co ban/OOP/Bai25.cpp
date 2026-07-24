#include <bits/stdc++.h>

using namespace std;

class NV{
private:
    static int dem;
    string manv, hoten, gioitinh, ngaysinh, diachi, masothue, ngaykyhopdong;
public:
    NV(){
        manv = "";
        hoten = "";
        gioitinh = "";
        ngaysinh = "";
        diachi = "";
        masothue = "";
        ngaykyhopdong = "";

        dem++;
        string s = to_string(dem);
        while (s.size() < 5){
            s = "0" + s;
        }
        manv = s;
    }

    void chuanHoaNgaySinh();
    void chuanHoaNgayKyHopDong();

    friend istream& operator >> (istream &in, NV &x){
        getline(in, x.hoten);
        getline(in, x.gioitinh);
        getline(in, x.ngaysinh);
        getline(in, x.diachi);
        getline(in, x.masothue);
        getline(in, x.ngaykyhopdong);

        x.chuanHoaNgayKyHopDong();
        x.chuanHoaNgaySinh();

        return in;
    }

    friend ostream& operator << (ostream &out, NV x){
        out << x.manv << " " << x.hoten << " " << x.gioitinh << " " << x.ngaysinh << ' ' << x.diachi << " " << x.masothue << " " << x.ngaykyhopdong;
        
        return out;
    }
};

int NV::dem = 0;

void NV::chuanHoaNgaySinh(){
    string res = "";
    string date = ngaysinh;

    for (int i = 0; i < (int)date.size(); i++){
        if (date[i] == '/') date[i] = ' ';
    }

    stringstream ss(date);
    string word;

    ss >> word;
    if (word.size() == 1) res += "0";
    res += word;
    res += "/";

    ss >> word;
    if (word.size() == 1) res += "0";
    res += word;
    res += "/";

    ss >> word;
    if (word.size() == 1) res += "000";
    else if (word.size() == 2) res += "00";
    else if (word.size() == 3) res += "0";
    res += word;
    
    this->ngaysinh = res;
}

void NV::chuanHoaNgayKyHopDong(){
    string res = "";
    string date = ngaykyhopdong;

    for (int i = 0; i < (int)date.size(); i++){
        if (date[i] == '/') date[i] = ' ';
    }

    stringstream ss(date);
    string word;

    ss >> word;
    if (word.size() == 1) res += "0";
    res += word;
    res += "/";

    ss >> word;
    if (word.size() == 1) res += "0";
    res += word;
    res += "/";

    ss >> word;
    if (word.size() == 1) res += "000";
    else if (word.size() == 2) res += "00";
    else if (word.size() == 3) res += "0";
    res += word;
    
    this->ngaykyhopdong = res;
}

int main(){
    int n;
    cin >> n;
    cin >> ws;

    vector<NV> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    for (int i = 0; i < n; i++){
        cout << v[i] << endl;
    }

    return 0;
}