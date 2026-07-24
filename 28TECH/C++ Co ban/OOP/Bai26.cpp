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

    int compDate(NV khac);

    bool operator < (NV khac){
        int comp = this->compDate(khac);
        if (comp == -1) return true;
        else if (comp == 1) return false;
        else{
            return this->manv < khac.manv;
        }
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

int NV::compDate(NV khac){
    // extract string date to int
    string date1 = this->ngaysinh, date2 = khac.ngaysinh;
    for (int i = 0; i < (int)date1.size(); i++){
        if (date1[i] == '/') date1[i] = ' ';
    }
    for (int i = 0; i < (int)date2.size(); i++){
        if (date2[i] == '/') date2[i] = ' ';
    }

    int d1, m1, y1, d2, m2, y2;
    
    stringstream ss1(date1);
    string word;
    ss1 >> word; d1 = stoi(word);
    ss1 >> word; m1 = stoi(word);
    ss1 >> word; y1 = stoi(word);

    stringstream ss2(date2);
    ss2 >> word; d2 = stoi(word);
    ss2 >> word; m2 = stoi(word);
    ss2 >> word; y2 = stoi(word);

    // comp
    if (y1 < y2) return -1;
    else if (y1 > y2) return 1;
    else{
        if (m1 < m2) return -1;
        else if (m1 > m2) return 1;
        else{
            if (d1 < d2) return -1;
            else if (d1 > d2) return 1;
            else return 0;
        }
    }
}

int main(){
    int n;
    cin >> n;
    cin >> ws;

    vector<NV> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++){
        cout << v[i] << endl;
    }

    return 0;
}