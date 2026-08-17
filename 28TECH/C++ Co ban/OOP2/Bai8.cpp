#include <bits/stdc++.h>

using namespace std;

class PhuongTien{
protected:
    string maxe, tenxe, hang, mausac;
    long long giaban;
public:
    void setMaXe(string maxe){
        this->maxe = maxe;
    }
    string getMaXe(){
        return maxe;
    }
    virtual void nhap(istream &in){
        getline(in, tenxe);
        getline(in, hang);
        getline(in, mausac);
    }

    virtual void xuat(ostream &out){
        out << maxe << " " << tenxe << " " << hang << " " << mausac << " ";
    }

    friend bool comp(PhuongTien *a, PhuongTien *b);

    virtual ~PhuongTien(){

    }
};

class XeMay : public PhuongTien{
private:
    int tocdotoida;
public:
    void nhap (istream &in) override{
        PhuongTien::nhap(in);
        in >> tocdotoida;
        in >> giaban;
        in.ignore();
    }
    void xuat (ostream &out) override{
        PhuongTien::xuat(out);
        out << tocdotoida << " " << giaban << "\n";
    }
};

class Oto : public PhuongTien{
private:
    int maluc;
public:
    void nhap (istream &in) override{
        PhuongTien::nhap(in);
        in >> maluc;
        in >> giaban;
        in.ignore();
    }
    void xuat (ostream &out) override{
        PhuongTien::xuat(out);
        out << maluc << " " << giaban << "\n";
    }
};

bool comp(PhuongTien *a, PhuongTien *b){
    if (a->giaban != b->giaban){
        return a->giaban > b->giaban;
    }
    return a->maxe < b->maxe;
}

int main(){
    int n;
    cin >> n;
    cin.ignore();

    vector<PhuongTien*> v(n);
    for (int i = 0; i < n; i++){
        string maxe;
        getline(cin, maxe);

        if (maxe.substr(0, 2) == "XM"){
            v[i] = new XeMay;
            v[i]->setMaXe(maxe);
            v[i]->nhap(cin);
        }
        else{
            v[i] = new Oto;
            v[i]->setMaXe(maxe);
            v[i]->nhap(cin);
        }
    }

    sort(v.begin(), v.end(), comp);

    cout << "DANH SACH OTO :\n"; 
    for(auto x : v){
        if (x->getMaXe().substr(0, 2) == "OT"){
            x->xuat(cout);
        }
    }

    cout << "DANH SACH XE MAY :\n"; 
    for(auto x : v){
        if (x->getMaXe().substr(0, 2) == "XM"){
            x->xuat(cout);
        }
    }

    return 0;
}