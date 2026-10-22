#include <bits/stdc++.h>

using namespace std;

class Employee{
protected:
    string manv, ten, ngaysinh, diachi;
    double hesoluong;
    string ngaybatdaulamviec;
public:
    virtual void nhap() {
        cout << "Ma nhan vien: ";
        getline(cin >> ws, manv);

        cout << "Ho ten: ";
        getline(cin >> ws, ten);

        cout << "Ngay sinh: ";
        getline(cin >> ws, ngaysinh);

        cout << "Dia chi: ";
        getline(cin >> ws, diachi);

        cout << "He so luong: ";
        cin >> hesoluong;

        cout << "Ngay bat dau lam viec: ";
        getline(cin >> ws, ngaybatdaulamviec);
    }

    virtual double tinhLuong(double luongcoban) const = 0;

    virtual ~Employee() {}
};

class Manager : public Employee {
public:
    double tinhLuong(double luongcoban) const override{
        return luongcoban * hesoluong;
    }
};

class Programmer : public Employee{
private: 
    double overtime;
public:
    void nhap() override {
        Employee::nhap();

        cout << "Tien overtime: ";
        cin >> overtime;
    }

    double tinhLuong(double luongcoban) const override {
        return luongcoban * hesoluong + overtime;
    }
};

class Designer : public Employee{
private:
    double bonus;
public:
    void nhap() override {
        Employee::nhap();

        cout << "Tien bonus: ";
        cin >> bonus;
    }

    double tinhLuong(double luongcoban) const override{
        return luongcoban * hesoluong + bonus;
    }
};

class Tester : public Employee{
private:
    int Error;
public:
    void nhap() override {
        Employee::nhap();

        cout << "Error: ";
        cin >> Error;
    }

    double tinhLuong(double luongcoban) const override{
        return luongcoban * hesoluong + Error * 200000;
    }
};

int main(){
    int n, loai;
    Employee* ds[100];

    cout << "Nhap so nhan vien: ";
    cin >> n;

    double luongcoban, tongluong = 0;

    cout << "Nhap luong co ban: ";
    cin >> luongcoban;

     for (int i = 0; i < n; i++) {
        cout << "\n=== Nhan vien " << i + 1 << " ===\n";
        cout << "1. Manager\n";
        cout << "2. Programmer\n";
        cout << "3. Designer\n";
        cout << "4. Tester\n";
        cout << "Chon loai nhan vien: ";
        cin >> loai;

        switch (loai) {
            case 1:
                ds[i] = new Manager();
                break;
            case 2:
                ds[i] = new Programmer();
                break;
            case 3:
                ds[i] = new Designer();
                break;
            case 4:
                ds[i] = new Tester();
                break;
            default:
                cout << "Loai nhan vien khong hop le!\n";
                i--;
                continue;
        }

        ds[i]->nhap();
    }

    for (int i = 0; i < n; i++) {
        double luong = ds[i]->tinhLuong(luongcoban);
        tongluong += luong;
    }

    cout << "Tong luong cong ty phai tra: " << tongluong << " VND\n";

    for (int i = 0; i < n; i++) {
        delete ds[i];
    }

    return 0;
}