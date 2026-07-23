#include <bits/stdc++.h>

using namespace std;

class SV{
private:
    string masv, hoten, lop, ngaysinh;
    double gpa;
public:
    SV(){
        masv = "";
        hoten = "";
        lop = "";
        ngaysinh = "";
        gpa = 0;
    }

    friend istream& operator >> (istream &in, SV &x){
        getline(in, x.hoten);
        in >> x.lop >> x.ngaysinh >> x.gpa;
        return in;
    }

    friend ostream& operator << (ostream &out, SV x){
        out << x.masv << " " << x.hoten << " " << x.lop << " " << x.ngaysinh << " " << fixed << setprecision(1) << x.gpa << endl;
        return out;
    }

    void setMaSV(string masv);
    void standardizeDate();
};

void SV::setMaSV(string masv){
    this->masv = masv;
}

void SV::standardizeDate(){
    int n = ngaysinh.size();
    for (int i = 0; i < n; i++){
        if (ngaysinh[i] == '/') ngaysinh[i] = ' ';
    }

    stringstream ss(ngaysinh);
    string word;
    string newDate = "";

    ss >> word;
    if (word.size() == 1){
        newDate += "0";
    }
    newDate += word;
    newDate += "/";

    ss >> word;
    if (word.size() == 1){
        newDate += "0";
    }
    newDate += word;
    newDate += "/";

    ss >> word;
    if (word.size() == 1){
        newDate += "000";
    }
    else if (word.size() == 2){
        newDate += "00";
    }
    else if (word.size() == 3){
        newDate += "0";
    }
    newDate += word;
    
    ngaysinh = newDate;
}

int main(){
    SV x;
    cin >> x;
    x.setMaSV("SV001");
    x.standardizeDate();
    cout << x;

    return 0;
}