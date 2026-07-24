#include <bits/stdc++.h>

using namespace std;

class SV{
private:
    string masv, hoten, ngaysinh, lop;
    double gpa;
    int stt;
public:
    SV(){
        masv = "";
        hoten = "";
        ngaysinh = "";
        lop = "";
        gpa = 0;
        stt = 0;
    }
    friend istream& operator >> (istream& in, SV &x){
        in >> ws;
        getline(in, x.hoten);
        getline(in, x.lop);
        getline(in, x.ngaysinh);
        in >> x.gpa;

        return in;
    }

    friend ostream& operator << (ostream &out, SV x){
        out << x.masv << " " << x.hoten << " " << x.lop << " " << x.ngaysinh << " " << fixed << setprecision(2) << x.gpa;

        return out;
    }

    void setMaSV(int stt){
        this->stt = stt;
        this->masv += "SV";

        if (stt < 10){
            masv += "00";
        }
        else if (stt < 100){
            masv += "0";
        }
        masv += to_string(stt);
    }

    void standardizeDate(){
        string date = ngaysinh;
        for (int i = 0; i < (int)date.size(); i++){
            if (date[i] == '/') date[i] = ' ';
        }

        stringstream ss(date);
        string word;
        string res = "";

        ss >> word;
        if (word.size() == 1){
            res += "0";
        }
        res += word;
        res += "/";

        ss >> word;
        if (word.size() == 1){
            res += "0";
        }
        res += word;
        res += "/";

        ss >> word;
        if (word.size() == 1){
            res += "000";
        }
        else if (word.size() == 2){
            res += "00";
        }
        else if (word.size() == 3){
            res += "0";
        }
        res += word;

        this->ngaysinh = res;
    }
};

int main(){
    int n;
    cin >> n;
    vector<SV> v(n);

    for (int i = 0; i < n; i++){
        cin >> v[i];
        v[i].setMaSV(i + 1);
        v[i].standardizeDate();
    }

    for (int i = 0; i < n; i++){
        cout << v[i] << endl;
    }

    return 0;
}