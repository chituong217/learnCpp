#include <bits/stdc++.h>

using namespace std;

class MH{
private:
    string ma, ten, donvi;
    int mua, ban, loinhuan;
    int stt;
public:
    friend istream& operator >> (istream &in, MH &x){
        getchar();
        getline(in, x.ten);
        getline(in, x.donvi);
        in >> x.mua >> x.ban;

        return in;
    }
    friend ostream& operator << (ostream &out, MH x){
        out << x.ma << " " << x.ten << " " << x.donvi << " " << x.mua << " " << x.ban << " " << x.loinhuan;

        return out;
    }
    void setMaMH(int stt);
    bool operator < (MH khac){
        if (this->loinhuan > khac.loinhuan) return true;
        else if (this->loinhuan < khac.loinhuan) return false;
        else {
            return this->stt < khac.stt;
        }
    }
    void tinhLoiNhuan(){
        this->loinhuan = ban - mua;
    }
};

void MH::setMaMH(int stt){
    string ma = "MH";
    if (stt < 10) ma += "000";
    else if (stt < 100) ma += "00";
    else if (stt < 1000) ma += "0";
    ma += to_string(stt);

    this->ma = ma;
    this->stt = stt;
}

int main(){
    int m;
    cin >> m;

    vector<MH> v(m);

    for (int i = 0; i < m; i++){
        cin >> v[i];
        v[i].setMaMH(i + 1);
        v[i].tinhLoiNhuan();
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < m; i++){
        cout << v[i] << endl;
    }

    return 0;
}