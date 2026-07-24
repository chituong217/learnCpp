#include <bits/stdc++.h>

using namespace std;

class Time{
private:
    int gio, phut, giay;
public:
    friend istream& operator >> (istream &in, Time &x){
        in >> x.gio >> x.phut >> x.giay;
        return in;
    }
    friend ostream& operator << (ostream &out, Time x){
        out << x.gio << " " << x.phut << " " << x.giay;
        return out;
    }
    bool operator < (Time khac){
        if (this->gio < khac.gio) return true;
        else if (this->gio > khac.gio) return false;
        else {
            if (this->phut < khac.phut) return true;
            else if (this->phut > khac.phut) return false;
            else {
                if (this->giay < khac.giay) return true;
                else return false;
            }
        }
    }
};

int main(){
    int n;
    cin >> n;
    vector<Time> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++){
        cout << v[i] << endl;
    }

    return 0;
}