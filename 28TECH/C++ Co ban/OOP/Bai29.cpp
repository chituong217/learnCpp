#include <bits/stdc++.h>

using namespace std;

class sv{
private:
    string masv, hoten, lop, email;
public:
    friend istream& operator >> (istream &in, sv &x){
        getline(in, x.masv);
        getline(in, x.hoten);
        getline(in, x.lop);
        getline(in, x.email);

        return in;
    }

    friend ostream& operator << (ostream &out, sv x){
        out << x.masv << ' ' << x.hoten << ' ' << x.lop << ' ' << x.email;

        return out;
    }

    bool operator < (sv khac){
        if (this->lop < khac.lop) return true;
        else if (this->lop > khac.lop) return false;
        else{
            return this->masv < khac.masv;
        }
    }
};

int main(){
    int n;
    cin >> n;
    cin >> ws;

    vector<sv> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++){
        cout << v[i] << endl;
    }

    return 0;
}