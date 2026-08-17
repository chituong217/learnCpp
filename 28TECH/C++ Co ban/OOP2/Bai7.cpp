#include <bits/stdc++.h>

using namespace std;

class Vehicle{
protected:
    string maxe, tenxe, hang, mausac;
    long long giaban;
public:
    virtual void nhapThongTin(istream &in){
        getline(in, tenxe);
        getline(in, hang);
        getline(in, mausac);
    }
    virtual void xuatThongTin(){
        cout << maxe << " " << tenxe << " " << hang << " " << mausac << " ";
    }

    string getHang(){
        return hang;
    }
    void setMaXe(string maxe){
        this->maxe = maxe;
    }
};

class Bike : public Vehicle{
private:
    int tocdotoida;
public:
    void nhapThongTin(istream &in) override{
        Vehicle::nhapThongTin(in);
        in >> tocdotoida;
        in >> giaban >> ws;
    }
    void xuatThongTin() override{
        Vehicle::xuatThongTin();
        cout << tocdotoida << " " << giaban << endl;
    }
};

class Car : public Vehicle{
private:
    int maluc;
public:
    void nhapThongTin(istream &in) override{
        Vehicle::nhapThongTin(in);
        in >> maluc;
        in >> giaban >> ws;
    }
    void xuatThongTin() override{
        Vehicle::xuatThongTin();
        cout << maluc << " " << giaban << endl;
    }
};

int main(){
    int n;
    cin >> n >> ws;

    vector<Bike> v1;
    vector<Car> v2;

    for (int i = 0; i < n; i++){
        string ma;
        getline(cin, ma);

        if (ma.substr(0, 2) == "XM"){
            Bike x;
            x.setMaXe(ma);
            x.nhapThongTin(cin);
            v1.push_back(x);
        }
        else{
            Car x;
            x.setMaXe(ma);
            x.nhapThongTin(cin);
            v2.push_back(x);
        }
    }

    string hang;
    getline(cin, hang);

    cout << "DANH SACH XE HANG " << hang << " :\n";

    for (Car x : v2){
        if (x.getHang() == hang){
            x.xuatThongTin();
        }
    }

    for (Bike x : v1){
        if (x.getHang() == hang){
            x.xuatThongTin();
        }
    }
    
    return 0;
}