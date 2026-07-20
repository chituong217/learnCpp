#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cctype>

#define MAX_LEN 31

using namespace std;

struct Nguoi{
    char HoTen[MAX_LEN];
    char DiaChi[MAX_LEN];
};

Nguoi* TaoNguoi(const char *pHt, const char *pDc){
    Nguoi* newNguoi = new Nguoi;
    strcpy(newNguoi->HoTen, pHt);
    strcpy(newNguoi->DiaChi, pDc);
    return newNguoi;
}

char* XuatNguoi(Nguoi *pN){
    static char stringNguoi[MAX_LEN * 10] = "";
    strcpy(stringNguoi, pN->HoTen);
    char DiaChi[MAX_LEN * 2] = "[";
    strcat(DiaChi, pN->DiaChi);
    strcat(DiaChi, "]");
    strcat(stringNguoi, DiaChi);
    strcat(stringNguoi, "\n");
    return stringNguoi;
}

void ChuanHoaTen(Nguoi* pN){
    char tmpName[MAX_LEN * 5] = "";
    strcpy(tmpName, pN->HoTen);
    char ans[MAX_LEN * 5] = "";
    char* token = strtok(tmpName, " ");
    while (token != NULL){
        token[0] = toupper(token[0]);
        int len = strlen(token);
        for (int i = 1; i < len; i++){
            token[i] = tolower(token[i]);
        }
        strcat(ans, token);
        strcat(ans, " ");
        token = strtok(NULL, " ");
    }
    strcpy(pN->HoTen, ans);
}

int main(){
    int n = 3;
    Nguoi* *pDsNguoi = new Nguoi*[n];
    pDsNguoi[0] = TaoNguoi("  lE tHI duNG    ", "HCM");
    pDsNguoi[1] = TaoNguoi("  ngUYen VAN ngUyEn    ", "HN");
    pDsNguoi[2] = TaoNguoi("  tRan trung trUc    ", "DN");

    cout << "Danh sach Nguoi moi tao: \n";
    for (int i = 0; i < n; i++){
        cout << XuatNguoi(pDsNguoi[i]);
    } 
    cout << "\nDanh sach Nguoi sau khi chuan hoa ten: \n";
    for (int i = 0; i < n; i++){
        ChuanHoaTen(pDsNguoi[i]);
        cout << XuatNguoi(pDsNguoi[i]);
    } 
    for (int i = 0; i < n; i++){
        delete pDsNguoi[i];
    }
    delete []pDsNguoi;
    return 0;
}