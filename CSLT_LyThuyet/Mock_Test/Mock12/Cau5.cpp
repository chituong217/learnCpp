#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

struct Employee{
    char manhanvien[12];
    char hoten[100];
    char ngaysinh[20];
    float hesoluong;
    double thuclanh;
};

void exportPayroll(char* inputFile, char* outputFile){
    ifstream fin;
    ofstream fout;

    fin.open(intputFile);
    fout.open(outputFile);

    if (fin.is_open() == false){
        cout << "Khong the doc file" << endl;
        return;
    }

    if (fout.is_open() == false){
        cout << "Khong the ghi file" << endl;
        return;
    }

    int n;
    cin >> n;
    fin.ignore();

    cout << "Ma NV | Ho Ten | Thuc Lanh " << endl;

    char line[1000];
    while (fin.getline(line, 1000)){
        char* id = strtok(line, ",");
        char* hoten = strtok(NULL, ",");
        char* ngaysinh = strtok(NULL, ",");
        char* hesoluongS = strtok(NULL, ",");

        if (id && hoten && hesoluongS){
            Employee nv;
            strcpy(nv.hoten, hoten);
            strcpy(nv.manhanvien, id);
            strcpy(nv.ngaysinh, ngaysinh);
            nv.hesoluong = atof(hesoluongS);

            nv.thuclanh = 1500000.0 * nv.hesoluong;

            fout << nv.manhanvien << " | " << nv.hoten << " | " << nv.thuclanh << endl;
        }
    }

    fout.close();
    fin.close();
}