#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

#define MAX_LEN 100

struct SinhVien{
    int MSSV;
    char HoTen[51];
};

char* SVToString(const SinhVien &sv){
    static char stringSV[MAX_LEN];
    sprintf(stringSV, "<%s>-<%d>", sv.HoTen, sv.MSSV);
    return stringSV;
}

void PrintArr(SinhVien *arr, const int &n){
    for (int i = 0; i < n; i++){
        cout << SVToString(arr[i]) << endl;
    }
}

typedef int(*SVComparer)(SinhVien, SinhVien);

int SVC1(SinhVien sv1, SinhVien sv2){
    if (sv1.MSSV > sv2.MSSV){
        return 1;
    }
    if (sv1.MSSV < sv2.MSSV){
        return -1;
    }
    return 0;
}

int SVC2(SinhVien sv1, SinhVien sv2){
    
    return strcmp(sv1.HoTen, sv2.HoTen);
}

void SortAsc(SinhVien *arrSV, const int &n, SVComparer svc){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (svc(arrSV[j], arrSV[j+1]) > 0){
                SinhVien svTemp = arrSV[j];
                arrSV[j] = arrSV[j+1];
                arrSV[j+1] = svTemp;
            }
        }
    }
}

void SortDesc(SinhVien *arrSV, const int &n, int (*svSoSanh)(SinhVien, SinhVien)){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (svSoSanh(arrSV[j], arrSV[j+1]) < 0){
                SinhVien svTemp = arrSV[j];
                arrSV[j] = arrSV[j+1];
                arrSV[j+1] = svTemp;
            }
        }
    }
}

SinhVien* LoadSV(const char *path, int &n){
    ifstream fin;
    
    // doc n
    n = 0;
    fin.open(path);

    if (fin.is_open() == false){
        cout << "Khong the mo file\n";
        return NULL;
    }

    char vungNho[1000];
    while (fin.getline(vungNho, 1000)){
        if (strlen(vungNho) > 0) n++;
    }

    fin.close();


    fin.open(path);

    SinhVien* arr = new SinhVien[n];
    int idx = 0;
    char line[MAX_LEN] = "";
    while (fin.getline(line, MAX_LEN) && idx < n){
        char* token = strtok(line, ";");

        if (token != NULL){
            int MSSV = atoi(token);
            arr[idx].MSSV = MSSV;

            token = strtok(NULL, ";");
            if (token != NULL) {
                strcpy(arr[idx].HoTen, token);
            }
            else {
                strcpy(arr[idx].HoTen, "No Name");
            }
            
            idx++;
        }
    }

    fin.close();
    n = idx;
    return arr;
}

int main(){
    const char *path = "C:\\Users\\XAOXIN\\Documents\\GITHUB\\learnCpp\\CSLT_ThucHanh\\W08_ThucHanh\\data.txt";
    int n = 0;
    SinhVien *arrSV1 = LoadSV(path, n);
    SinhVien *arrSV2 = LoadSV(path, n);
    cout << "****************Arr begin****************" << endl;
    PrintArr(arrSV1, n);
    
    SortAsc(arrSV1, n, SVC1);
    cout << "**********Arr sorted mode 1**********" << endl;
    PrintArr(arrSV1, n);
    
    SortDesc(arrSV2, n, SVC2);
    cout << "**********Arr sorted mode 2**********" << endl;
    PrintArr(arrSV2, n);

    delete []arrSV1;
    delete []arrSV2;
    
    system("pause");
    return 0;
}