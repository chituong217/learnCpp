#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iomanip>

using namespace std;

struct Student{
    char mssv[10];
    char hoten[1000];
    float toan;
    float ly;
    float hoa;
    float gpa;
};

void processGradeReport(char* inputFile, char* outputFile){
    ifstream fin;
    ofstream fout;

    fin.open(inputFile);
    fout.open(outputFile);

    if (fin.is_open() == false || fout.is_open == false){
        cout << "Khong the mo file" << endl;
        return;
    }

    int soluonghocsinh;
    fin >> soluonghocsinh;

    int idx = 0;
    Student* ds = new Student[soluonghocsinh];

    char line[1000];
    while (fin.getline(line, 1000)){
        char* mssv = strtok(line, ",");
        char* hoten = strtok(NULL, ",");
        char* toanS = strtok(NULL, ",");
        char* lyS = strtok(NULL, ",");
        char* hoaS = strtok(NULL, ",");

        if (mssv && hoten && toanS && lyS && hoaS){
            float toan = atof(toanS);
            float ly = atof(lyS);
            float hoa = atof(hoaS);

            float diemtrungbinh = (toan + ly + hoa) / 3.0;

            strcpy(ds[idx].mssv, mssv);
            strcpy(ds[idx].hoten, hoten);
            ds[idx].toan = toan;
            ds[idx].ly = ly;
            ds[idx].hoa = hoa;
            ds[idx].gpa = diemtrungbinh;

            idx++;
        }
    }

    fout << "MSSV | Ho Ten | DTB" << endl;
    fout << "--------------------" << endl;
    for (int i = 0; i < idx; i++){
        if (ds[i].gpa >= 8.0){
            fout << fixed << setprecision(2) << ds[i].mssv << " | " << ds[i].hoten << " | " << ds[i].gpa << endl;
        }
    }

    fout.close();
    fin.close();

    delete []ds;
}
