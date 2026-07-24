#include <bits/stdc++.h>

using namespace std;

class SV{
private:
    static int dem;
    string masv, hoten, ngaysinh, lop;
    double gpa;
public:
    void standardizeDate();
    void standardizeName();
    SV(){
        masv = "";
        hoten = "";
        ngaysinh = "";
        lop = "";
        gpa = 0;

        dem++;
        string s = to_string(dem);
        while (s.size() < 3){
            s = "0" + s;
        }

        masv = "SV" + s;
    }
    friend istream& operator >> (istream &in, SV &x){
        in >> ws;
        getline(in, x.hoten);
        getline(in, x.lop);
        getline(in, x.ngaysinh);
        in >> x.gpa;

        x.standardizeDate();
        x.standardizeName();

        return in;
    }
    friend ostream& operator << (ostream &out, SV x){
        out << x.masv << " " << x.hoten << " " << x.lop << " " << x.ngaysinh << " " << fixed << setprecision(2) << x.gpa;

        return out;
    }
};

int SV::dem = 0;

void SV::standardizeDate(){
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

void SV::standardizeName(){
    string res = "";
    string name = hoten;

    stringstream ss(name);
    string word;

    while (ss >> word){
        for (int i = 0; i < (int)word.size(); i++){
            if (i == 0) word[i] = toupper(word[i]);
            else word[i] = tolower(word[i]);
        }
        res += word;
        res += " ";
    }
    res.pop_back();

    this->hoten = res;
}

int main(){
    int n;
    cin >> n;
    vector<SV> v(n);

    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    for (int i = 0; i < n; i++){
        cout << v[i] << endl;
    }

    return 0;
}