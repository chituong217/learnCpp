#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

struct Ticket{
    char mave[11];
    char tenphim[51];
    long long giave;
    int soluong;
};

void reportRevenue(char* inputFile, char* outputFile){
    ifstream fin;
    ofstream fout;

    fin.open(inputFile);
    fout.open(outputFile);

    if (fin.is_open() == false){
        cout << "Khong the doc file" << endl;
        return;
    }
    if (fout.is_open() == false){
        cout << "Khong the ghi file" << endl;
        return;
    }

    long long doanhthuMax = 0;
    Ticket vecoDoanhThuMax;

    char line[1000];
    while (fin.getline(line, 1000)){
        char* mave = strtok(line, ",");
        char* tenphim = strtok(NULL, ",");
        char* giaveS = strtok(NULL, ",");
        char* soluongS = strtok(NULL, ",");

        if (mave && tenphim && giaveS && soluongS){
            long long giave = atoll(giaveS);
            int soluong = atoi(soluongS);

            long long doanhthu = giave * soluong;
            if (doanhthu > doanhthuMax){
                doanhthuMax = doanhthu;
                strcpy(vecoDoanhThuMax.mave, mave);
                strcpy(vecoDoanhThuMax.tenphim, tenphim);
                vecoDoanhThuMax.giave = giave;
                vecoDoanhThuMax.soluong = soluong;
            }
        }
    }

    fout << vecoDoanhThuMax.tenphim << " - " << doanhthuMax << endl;

    fout.close();
    fin.close();
}