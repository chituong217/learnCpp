#include <bits/stdc++.h>

using namespace std;

class Time{
private:
    int gio, phut, giay;
public:
    Time();
    Time(int h, int m, int s);
    Time(const Time& other);
    void Xuat() const;
    void Tang1Giay();
};

Time::Time() : gio(0), phut(0), giay(0){
}

Time::Time(int h, int m, int s) : gio(h), phut(m), giay(s){
    if (gio < 0 || gio > 23) gio = 0;
    if (phut < 0 || phut > 59) phut = 0;
    if (giay < 0 || giay > 59) giay = 0;
}

Time::Time(const Time& other) : gio(other.gio), phut(other.phut), giay(other.giay){

}

void Time::Xuat() const{
    string h = to_string(gio);
    string m = to_string(phut);
    string s = to_string(giay);
    if (h.size() == 1) h = "0" + h;
    if (m.size() == 1) m = "0" + m;
    if (s.size() == 1) s = "0" + s;

    cout << h << ":" << m << ":" << s << endl;
}

void Time::Tang1Giay(){
    giay++;
    if (giay == 60){
        giay = 0;
        phut++;
    }
    if (phut == 60){
        phut = 0;
        gio++;
    }
    if (gio == 24){
        gio = 0;
    }
}

int main(){

    return 0;
}