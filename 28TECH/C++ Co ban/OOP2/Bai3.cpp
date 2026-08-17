#include <bits/stdc++.h>

using namespace std;

class Person{
protected:
    string ten, ngaysinh, diachi;
public:
    void chuanHoaTen();
    void chuanHoaDiaChi();
    void chuanHoaNgaySinh();

    void inThongTin(){
        cout << ten << ' ' << ngaysinh << ' ' << diachi << ' ';
    }
};

void Person::chuanHoaTen(){
    stringstream ss(ten);
    string word;

    string res = "";
    while (ss >> word){
        for (int i = 0; i < (int)word.size(); i++){
            if (i == 0){
                word[i] = toupper(word[i]);
            }
            else{
                word[i] = tolower(word[i]);
            }
        }

        res += word;
        res += " ";
    }
    res.pop_back();

    this->ten = res;
}

void Person::chuanHoaDiaChi(){
    stringstream ss(diachi);
    string word;

    string res = "";
    while (ss >> word){
        for (int i = 0; i < (int)word.size(); i++){
            if (i == 0){
                word[i] = toupper(word[i]);
            }
            else{
                word[i] = tolower(word[i]);
            }
        }

        res += word;
        res += " ";
    }
    res.pop_back();

    this->diachi = res;
}

void Person::chuanHoaNgaySinh(){
    for (int i = 0; i < (int)ngaysinh.size(); i++){
        if (ngaysinh[i] == '/') ngaysinh[i] = ' ';
    }

    string date = "";
    stringstream ss(ngaysinh);
    string word;

    ss >> word;
    if (word.size() == 1) date += "0";
    date += word;
    date += "/";

    ss >> word;
    if (word.size() == 1) date += "0";
    date += word;
    date += "/";

    ss >> word;
    while (word.size() < 4){
        word = "0" + word;
    }
    date += word;

    this->ngaysinh = date;
}

class SV : public Person{
private:
    string masv, lop;
    double gpa;
public:
    friend istream& operator >> (istream &in, SV &x){
        getline(in, x.ten);
        getline(in, x.ngaysinh);
        getline(in, x.diachi);

        x.chuanHoaTen();
        x.chuanHoaDiaChi();
        x.chuanHoaNgaySinh();

        getline(in, x.lop);
        in >> x.gpa >> ws;

        return in;
    }

    void setMaSV(string masv){
        this->masv = masv;
    }

    void inThongTin(){
        cout << masv << ' ';
        Person::inThongTin();
        cout << lop << ' ' << fixed << setprecision(2) << gpa << endl;
    }
};

class GV : public Person{
private:
    string magv, khoa;
    long long luong;
public:
    friend istream& operator >> (istream &in, GV &x){
        getline(in, x.ten);
        getline(in, x.ngaysinh);
        getline(in, x.diachi);

        x.chuanHoaTen();
        x.chuanHoaDiaChi();
        x.chuanHoaNgaySinh();

        getline(in, x.khoa);
        in >> x.luong >> ws;
        
        return in;
    }

    void setMaGV(string magv){
        this->magv = magv;
    }

    void inThongTin(){
        cout << magv << ' ';
        Person::inThongTin();
        cout << khoa << ' ' << luong << endl;
    }
};


int main(){
    int n;
    cin >> n >> ws;

    vector<SV> v1;
    vector<GV> v2;

    for (int i = 0; i < n; i++){
        string ma;
        getline(cin, ma);

        if (ma[0] == 'S'){
            SV x;
            x.setMaSV(ma);
            cin >> x;
            v1.push_back(x);
        }
        else{
            GV x;
            x.setMaGV(ma);
            cin >> x;
            v2.push_back(x);
        }
    }

    cout << "DANH SACH GIAO VIEN :" << endl;

    for (GV x : v2){
        x.inThongTin();
    }

    cout << "DANH SACH SINH VIEN :" << endl;

    for (SV x : v1){
        x.inThongTin();
    }

    return 0;
}