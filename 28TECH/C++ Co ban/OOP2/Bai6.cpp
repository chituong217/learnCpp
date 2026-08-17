#include <bits/stdc++.h>

using namespace std;

class Person{
protected:
    string ma, ten, ngaysinh, diachi; 
public:
    void chuanHoaTen();
    void chuanHoaDiaChi();
    void chuanHoaNgaySinh();

    virtual void inThongTin(){
        cout << ma << " " << ten << ' ' << ngaysinh << ' ' << diachi << ' ';
    }
    virtual void nhapThongTin(istream &in){
        getline(in, ten);
        getline(in, ngaysinh);
        getline(in, diachi);

        chuanHoaTen();
        chuanHoaNgaySinh();
        chuanHoaDiaChi();
    }
    void setMa(string ma){
        this->ma = ma;
    }
    string getDiaChi(){
        return diachi;
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
    string lop;
    double gpa;
public:
    void inThongTin() override{
        Person::inThongTin();
        cout << lop << " " << fixed << setprecision(2) << gpa << endl;
    }
    void nhapThongTin(istream &in) override{
        Person::nhapThongTin(in);
        getline(in, lop);
        in >> gpa >> ws;
    }
    string getLop(){
        return lop;
    }
};

class GV : public Person{
private:
    string khoa, lopchunhiem;
    long long luong;
public:
    void inThongTin() override{
        Person::inThongTin();
        cout << khoa << " " << luong << " " << lopchunhiem << endl;
    }
    void nhapThongTin(istream &in) override{
        Person::nhapThongTin(in);
        getline(in, khoa);
        in >> luong >> ws;
        getline(in, lopchunhiem);
    }
    string getLopChuNhiem(){
        return lopchunhiem;
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

        if (ma.substr(0, 2) == "SV"){
            SV x;
            x.setMa(ma);
            x.nhapThongTin(cin);
            v1.push_back(x);
        }
        else{
            GV x;
            x.setMa(ma);
            x.nhapThongTin(cin);
            v2.push_back(x);
        }
    }

    string lop;
    getline(cin, lop);

    cout << "DANH SACH GIAO VIEN PHU TRACH LOP " << lop << " :\n";
    for (GV x : v2){
        if (x.getLopChuNhiem() == lop)
            x.inThongTin();
    }

    cout << "DANH SACH SINH VIEN LOP " << lop << " :\n";
    for (SV x : v1){
        if (x.getLop() == lop)
            x.inThongTin();
    }

    return 0;
}