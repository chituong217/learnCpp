#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct Order{
    char madon[11];
    char tenkhach[51];
    int soluong;
    long long dongia;
    long long thanhtien;
};

void saveHighValueOrders(char* inputFile, char* outputFile, long long threshold){
    ifstream fin;
    ofstream fout;

    fin.open(inputFile);
    fout.open(outputFile);

    if (fin.is_open() == false || fout.is_open() == false){
        cout << "Khong the mo file" << endl;
        return;
    }

    int n;
    fin >> n;
    fin.ignore();

    Order* ds = new Order[n];
    int idx = 0;

    char line[1000];
    while(fin.getline(line, 1000)){
        char* madon = strtok(line, ",");
        char* tenkhach = strtok(NULL, ",");
        char* soluongS = strtok(NULL, ",");
        char* dongiaS = strtok(NULL, ",");

        if (madon && tenkhach && soluongS && dongiaS){
            strcpy(ds[idx].madon, madon);
            strcpy(ds[idx].tenkhach, tenkhach);

            ds[idx].soluong = atoi(soluongS);
            ds[idx].dongia = atoll(dongiaS);

            ds[idx].thanhtien = 1ll * ds[idx].soluong * ds[idx].dongia;

            if (ds[idx].thanhtien >= threshold){
                fout << ds[idx].madon << " - " << ds[idx].tenkhach << " - " << ds[idx].thanhtien << endl;
            }

            idx++;
        }
    }

    fout.close();
    fin.close();

    delete []ds;
}