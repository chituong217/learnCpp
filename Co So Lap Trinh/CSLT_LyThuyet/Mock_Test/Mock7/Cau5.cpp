#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

struct Student{
    char id[20];
    char name[50];
    float math, phys, eng;
};

void listScholarshipStudents(char* filePath){
    ifstream fin;

    fin.open(filePath);
    
    if (fin.is_open() == false){
        cout << "Khong the mo file" << endl;
        return;
    }

    Student ds[1000];
    char line[1000];
    int idx = 0;

    while (fin.getline(line, 1000)){
        char* id = strtok(line, ",");
        char* name = strtok(NULL, ",");
        char* mathS = strtok(NULL, ",");
        char* physS = strtok(NULL, ",");
        char* engS = strtok(NULL, ",");

        if (id && name && mathS && physS && engS){
            strcpy(ds[idx].id, id);
            strcpy(ds[idx].name, name);
            ds[idx].math = atof(mathS);
            ds[idx].phys = atof(physS);
            ds[idx].eng = atof(engS);

            idx++;
        }
    }

    for (int i = 0; i < idx; i++){
        bool ok = false;
        float gpa = (ds[i].math + ds[i].phys + ds[i].eng)/3.0;
        if (gpa >= 8.0 && ds[i].math >= 5.0 && ds[i].phys >= 5.0 && ds[i].eng >= 5.0){
            ok = true;
        }

        if (ok == true){
            cout << fixed << setprecision(2) << ds[i].name << " - DTB: " << gpa << endl;
        }
    }

    fin.close();
}