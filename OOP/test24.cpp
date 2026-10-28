#include <bits/stdc++.h>

using namespace std;

class TuitionPolicy{
private:
    int hocphigoc;
public:
    TuitionPolicy() = default;
    TuitionPolicy(int hpg) : hocphigoc(hpg){

    }
    int getHocPhiGoc(){
        return hocphigoc;
    }

    virtual int tinhHocPhi() = 0;

    virtual void display() = 0;

    virtual ~TuitionPolicy() = default;
};

class TuitionStudent : public TuitionPolicy{
public:
    TuitionStudent(int hpg) : TuitionPolicy(hpg){

    }
    int tinhHocPhi() override{
        return getHocPhiGoc();
    }
    void display() override{
        cout << "Sinh vien thuong, hoc phi :" << tinhHocPhi() << endl;
    }
};

class TuitionStudentHB : public TuitionPolicy{
public:
    TuitionStudentHB(int hpg) : TuitionPolicy(hpg){

    }

    int tinhHocPhi() override{
        return getHocPhiGoc() / 2;
    }

    void display() override{
        cout << "Sinh vien hoc bong, hoc phi :" << tinhHocPhi() << endl;
    }
};

class TuitionStudentTD : public TuitionPolicy{
public:
    TuitionStudentTD(int hpg) : TuitionPolicy(hpg){

    }

    int tinhHocPhi() override{
        return 0;
    }

    void display() override{
        cout << "Sinh vien trao doi, hoc phi :" << tinhHocPhi() << endl;
    }
};

int main(){
    TuitionStudent a(10000000);
    TuitionStudentHB b(10000000);
    TuitionStudentTD c(10000000);

    vector<TuitionPolicy*> v;
    v.push_back(&a);
    v.push_back(&b);
    v.push_back(&c);

    for (auto x : v){
        x->display();
    }

    return 0;
}