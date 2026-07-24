#include <bits/stdc++.h>

using namespace std;

class hs{
private:
    static int dem;
    string mahs, ten;
    double d1, d2, d3, d4, d5, d6, d7, d8, d9, d10;

    double gpa;
    string xeploai;
public:
    hs(){
        dem++;
        this->mahs = "HS0" + to_string(dem);
    }

    friend istream& operator >> (istream& in, hs &x){
        in >> ws;
        getline(in, x.ten);
        in >> x.d1 >> x.d2 >> x.d3 >> x.d4 >> x.d5 >> x.d6 >> x.d7 >> x.d8 >> x.d9 >> x.d10;

        x.gpa = (x.d1 + x.d2 + x.d3 + x.d4 + x.d5 + x.d6 + x.d7 + x.d8 + x.d9 + x.d10) / 10.0;
        if (x.gpa >= 9.0) x.xeploai = "XUAT SAC";
        else if (x.gpa >= 8.0) x.xeploai = "GIOI";
        else if (x.gpa >= 7.0) x.xeploai = "KHA";
        else if (x.gpa >= 5.0) x.xeploai = "TB";
        else x.xeploai = "YEU";

        return in;
    }

    friend ostream& operator << (ostream &out, hs x){
        out << x.mahs << ' ' << x.ten << " " << fixed << setprecision(1) << x.gpa << " " << x.xeploai;

        return out;
    }

    bool operator < (hs khac){
       if (this->gpa > khac.gpa) return true;
       else if (this->gpa < khac.gpa) return false;
       else{
            return this->mahs < khac.mahs;
       } 
    }
};

int hs::dem = 0;

int main(){
    int n;
    cin >> n;

    vector<hs> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++){
        cout << v[i] << endl;
    }

    return 0;
}