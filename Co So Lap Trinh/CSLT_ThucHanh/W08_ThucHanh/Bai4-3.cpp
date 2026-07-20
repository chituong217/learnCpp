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

void xuatTaiKhoanTimKiem(account* ds, int n){
    if (n == 0){
        cout << "Danh sach rong" << endl;;
        return;
    }

    char find[MAX_LEN];
    cin.getline(find, MAX_LEN);

    // bien tim thay trong trg hop ko tm thay
    bool timthay = false;

    //in thuong find de tien tim kiem
    for (int j = 0; j < (int)strlen(find); j++){
            find[j] = tolower(find[j]);
    }

    for (int i = 0; i < n; i++){
        char fullname[MAX_LEN * 4] = "";
        strcat(fullname, ds[i].hoten.lastName);
        strcat(fullname, " "); // them dau cach
        
        // neu co dem thi noi
        if (strlen(ds[i].hoten.middleName) > 0) {
            strcat(fullname, ds[i].hoten.middleName);
            strcat(fullname, " ");
        }

        // noi ten
        strcat(fullname, ds[i].hoten.firstName);
        // da noi full name ok
        
        // in thuong full name
        // vi strstr phan biet hoa thuong

        for (int j = 0; j < (int)strlen(fullname); j++){
            fullname[j] = tolower(fullname[j]);
        }
        // check xem co find trog full name ko
        if (strstr(fullname, find) != NULL){
            timthay = true;
            cout << "Tai khoan duoc tim thay: ";
            xuatTaiKhoan(ds[i]);
        }
    }

    if (timthay == false){
        cout << "Khong tim thay" << endl;
    }
}
