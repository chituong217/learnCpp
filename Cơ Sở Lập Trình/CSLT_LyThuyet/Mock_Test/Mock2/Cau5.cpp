#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>

using namespace std;

void filterStudentsByYear(char* filePath, int year){
    ifstream fin;
    fin.open(filePath);
    
    if (!fin.is_open()){
        cout << "Khong the mo file" << endl;
        return;
    }
    char line[1000];
    while(fin.getline(line, 1000)){
        char* id = strtok(line, "-");
        char* name = strtok(NULL, "-");
        char* date = strtok(NULL, "-");
        char* yearS = strtok(date, "/");
        yearS = strtok(NULL, "/");
        yearS = strtok(NULL, "/");
        int yearI = atoi(yearS);
        if (yearI == year){
            cout << id << "- " << name << endl;
        }
    }

    fin.close();
}