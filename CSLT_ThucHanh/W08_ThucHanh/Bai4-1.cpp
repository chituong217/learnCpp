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

bool isPasswordValid(char pass[]) {
    // do dai mk
    if (strlen(pass) < 6) return false;
    // cac bien cho dk
    bool hasUpper = false;
    bool hasAlpha = false;
    bool hasDigit = false;
    bool hasSpecial = false;
    // cac kt db
    const char specialChars[] = ",.?:;~-_";

    for (int i = 0; i < (int)strlen(pass); i++) {
        if (isupper(pass[i])) hasUpper = true;
        if (isalpha(pass[i])) hasAlpha = true;
        if (isdigit(pass[i])) hasDigit = true;
        if (strchr(specialChars, pass[i]) != NULL){
            hasSpecial = true;
        } 
    }
    // gop cac dki lai
    return (hasUpper && hasAlpha && hasDigit && hasSpecial);
}

account nhapTaiKhoan(){
    account taikhoan;

    // nhap vao username o day
    char tendangnhap[MAX_LEN];
    bool ok;
    do{
        ok = true;
        cout << "Nhap vao ten dang nhap (ko chua chu 'admin') : ";
        cin.getline(tendangnhap, MAX_LEN);
        // kiem tra xem co 'admin' ko
        if (strstr(tendangnhap, "admin") != NULL){
            ok = false;
        }
        // neu ok van con = true tuc la ko xuat hien 'admin'
    } while (ok == false);
    // da nhap vao username va gan username vao acc
    if (strlen(tendangnhap) > 0){
        strcpy(taikhoan.username, tendangnhap);
    }
    else{
        strcpy(taikhoan.username, "");
    }
    // da gan ten vao account

    // xu li mat khau
    char matkhau[MAX_LEN];
    char matkhau2[MAX_LEN];
    // check cac dieu kien
    do{
        ok = true;
        cout << "Nhap vao mat khau (tren 6 ki tu, co ki tu in hoa, co chu cai, co so, co 1 trong cac ki tu : dau phay, cham, hoi, hai cham, cham phay, nga, gach ngang, gach duoi): ";
        cin.getline(matkhau, MAX_LEN);
        cout << "Nhap lai mat khau: ";
        cin.getline(matkhau2, MAX_LEN);
        // check mk2 co giong mk1
        if (strcmp(matkhau2, matkhau) != 0){
            ok = false;
        }
        if (isPasswordValid(matkhau) == false){
            ok = false;
        }
    } while (ok == false);
    // neu da ok thi gan vao matkhau
    if (strlen(matkhau) > 0){
        strcpy(taikhoan.password, matkhau);
    }
    else{
        strcpy(taikhoan.password, "");
    }
    // da gan mat khau vao account

    // xu li ho ten
    char hoten[MAX_LEN];
    int sotu = 0;
    do{
        cout << "Nhap vao ho ten (it nhat 2 tu) :";
        cin.getline(hoten, MAX_LEN);
        // kiem tra co nhieu hon 2 tu ko
        sotu = 0;
        // copy lai
        char kiemtra[MAX_LEN];
        strcpy(kiemtra, hoten);
        // dung strtok dem
        char* token = strtok(kiemtra, " ");
        while (token != NULL){
            sotu++;
            token = strtok(NULL, " ");
        }
    } while (sotu < 2);
    // chuoi ho ten da ok
    // bat dau xu li gan vao trong name
    if (sotu == 2){
        char word[MAX_LEN];
        // copy lai
        strcpy(word, hoten);
        // gan ho
        char* token = strtok(word, " ");
        strcpy(taikhoan.hoten.lastName, token);
        // gan ten dem la rong
        strcpy(taikhoan.hoten.middleName, "");
        // gan ten
        token = strtok(NULL, " ");
        strcpy(taikhoan.hoten.firstName, token);
    }
    else{
        int cnt = 0;
        // copy lai
        char word[MAX_LEN];
        strcpy(word, hoten);
        // gan ho
        char* token = strtok(word, " ");
        cnt++;
        strcpy(taikhoan.hoten.lastName, token);
        // xu li middle
        strcpy(taikhoan.hoten.middleName, "");
        while (cnt < sotu - 1){
            token = strtok(NULL, " ");
            strcat(taikhoan.hoten.middleName, token);
            if (cnt < sotu - 2){
                strcat(taikhoan.hoten.middleName, " ");
            }
            cnt++;
        }
        // gan ten
        token = strtok(NULL, " ");
        strcpy(taikhoan.hoten.firstName, token);
    }
    // da xu li xong ho ten

    // xu ly email
    char email[MAX_LEN];
    do{
        ok = true;
        cout << "Nhap vao email (co @ va .): ";
        cin.getline(email, MAX_LEN);
        bool okcham = false;
        bool okacong = false;
        for (int i = 0; i < (int)strlen(email); i++){
            // check co cham va a cong
            if (email[i] == '.') okcham = true;
            if (email[i] == '@') okacong = true;
        }
        // gop lai 2 dkien
        if (okcham == false || okacong == false) ok = false;
    } while (ok == false);

    // gan email vao acc
    if (strlen(email) > 0){
        strcpy(taikhoan.email, email);
    }
    else{
        strcpy(taikhoan.email, "");
    }
    // da xog email

    // xu li ngay sinh va gan tuoi
    char date[MAX_LEN];
    cout << "Nhap vao ngay thang nam sinh (dd/mm/yyyy): ";
    cin.getline(date, MAX_LEN);
    // gan date
    if (strlen(date) > 0){
        strcpy(taikhoan.date, date);
    }
    else{
        // mac dinh de chong loi
        strcpy(taikhoan.date, "01/01/2000");
    }
    // xu li tuoi
    // tim dau gach cuoi
    char *ptr = strrchr(taikhoan.date, '/'); 
    
    int birthYear = 0;
    if (ptr != NULL) {
        birthYear = atoi(ptr + 1); 
    }
    // tinh den nam 2025
    taikhoan.age = 2025 - birthYear;
    // da gan xong tuoi

    return taikhoan;
}

account* nhapDStaikhoan(int &n){
    do {
        cout << ">> Nhap so luong tai khoan can tao: ";
        cin >> n;
    } while (n <= 0);

    cin.ignore(); 

    account *ds = new account[n];

    for(int i = 0; i < n; i++){
        cout << "Tai khoan thu [" << i+1 << " ]\n";
        ds[i] = nhapTaiKhoan();
    }
    
    return ds;
}

int main(){
    return 0;
}