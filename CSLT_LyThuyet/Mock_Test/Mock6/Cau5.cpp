#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct employee{
    char id[100];
    char checkin[10];
    char checkout[10];
    int time;
};

void findHardWorkingEmployee(char* filePath){
    ifstream fin;
    employee ds[100];
    int idx = 0;

    fin.open(filePath);

    if (fin.is_open() == false){
        cout << "Ko the mo file" << endl;
        return;
    }

    char line[1000];

    while(fin.getline(line, 1000)){
        char* id = strtok(line, ",");
        char* checkin = strtok(NULL, ",");
        char* checkout = strtok(NULL, ",");

        if (id && checkin && checkout){
            strcpy(ds[idx].id, id);
            strcpy(ds[idx].checkin, checkin);
            strcpy(ds[idx].checkout, checkout);
            idx++;
        }
    }

    for (int i = 0; i < idx; i++){
        char* token = strtok(ds[i].checkout, ":");
        int time = 0;
        time = atoi(token) * 60;
        token = strtok(NULL, ":");
        time += atoi(token);
        ds[i].time = time;
    }

    for (int i = 0; i < idx; i++){
        char* token = strtok(ds[i].checkin, ":");
        int time = 0;
        time = atoi(token) * 60;
        token = strtok(NULL, ":");
        time += atoi(token);
        ds[i].time -= time;
    }

    for (int i = 0; i < idx; i++){
        if (ds[i].time > 480){
            cout << ds[i].id << " - " << "Thoi gian: " << ds[i].time << "phut" << endl;
        }
    }

    fin.close();
}
