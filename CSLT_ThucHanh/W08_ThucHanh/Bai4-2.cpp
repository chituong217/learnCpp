#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cctype>

#define MAX_LEN 100

using namespace std;

struct name{
    char lastName[MAX_LEN];
    char middleName[MAX_LEN];
    char firstName[MAX_LEN];
};

struct account{
    char username[MAX_LEN];
    char password[MAX_LEN];
    name hoten;
    char email[MAX_LEN];
    char date[MAX_LEN];
    int age;
};

void xuatTaiKhoan(account taikhoan){
    cout << "---------------------------\n";
    cout << "Ten username: " << taikhoan.username << endl;
    cout << "Mat khau: " << taikhoan.password << endl;
    cout << "Ho: " << taikhoan.hoten.lastName << endl;
    cout << "Ten dem: " << taikhoan.hoten.middleName << endl;
    cout << "Ten: " << taikhoan.hoten.firstName << endl;
    cout << "Email: " << taikhoan.email << endl;
    cout << "Tuoi: " << taikhoan.age << endl;
    cout << "---------------------------\n";
}

void xuatDStaikhoan(account* ds, int n){
    if (n == 0){
        cout << "Danh sach rong" << endl;;
        return;
    }

    for (int i = 0; i < n; i++){
        cout << "Tai khoan thu [" << i+1 << " ]\n";
        xuatTaiKhoan(ds[i]);
    }
}