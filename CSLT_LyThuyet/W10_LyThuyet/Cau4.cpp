#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <iomanip>

using namespace std;

struct Package{
    char id[18];
    char name[16];
    char diachi[51];
    char sdt[11];
    float khoiluong;
};

int docdanhsach(const char* filePath, Package ds[]){
    ifstream fin;

    fin.open(filePath);
    
    if (fin.is_open() == false){
        cout << "Khong the mo file" << endl;
        return 0;
    }

    int n = 0;
    char line[1000];

    fin.getline(line, 1000);
    while (fin.getline(line, 1000)){
        char* id = strtok(line, "|");
        char* name = strtok(NULL, "|");
        char* diachi = strtok(NULL, "|");
        char* sdt = strtok(NULL, "|");
        char* khoiluongS = strtok(NULL, "|");
        if (id && name && diachi && sdt && khoiluongS){
            strcpy(ds[n].id, id);
            strcpy(ds[n].name, name);
            strcpy(ds[n].diachi, diachi);
            strcpy(ds[n].sdt, sdt);

            float khoiluong = atof(khoiluongS);
            ds[n].khoiluong = khoiluong;

            n++;
        }
    }

    fin.close();

    return n;
}

void xuatThongTin(Package ds[], int n, const char *deliveryDist, const char* filePath){
    ofstream fout;

    if (n == 0) return;

    fout.open(filePath);

    if (fout.is_open() == false){
        cout << "Khong the mo file\n"; 
        return;
    }

    fout << "Ma don hang|Ten nguoi nhan|Dia chi|So dien thoai|Khoi luong\n";

    for (int i = 0; i < n; i++){
        char copyPos[1000];
        strcpy(copyPos, ds[i].diachi);

        char* token = strtok(copyPos, ",");
        token = strtok(NULL, ",");
        token = strtok(NULL, ",");
        token = strtok(NULL, ",");

        int len = strlen(token);
        char District[1000];
        for (int j = 1; j < len; j++){
            District[j - 1] = token[j];
        }
        District[len - 1] = '\0';

        if (strcmp(District, deliveryDist) == 0){
            fout << fixed << setprecision(1) << ds[i].id << "|" << ds[i].name << "|" << ds[i].diachi << "|" << ds[i].sdt << "|" << ds[i].khoiluong << endl;
        }
    }

    fout.close();
}
