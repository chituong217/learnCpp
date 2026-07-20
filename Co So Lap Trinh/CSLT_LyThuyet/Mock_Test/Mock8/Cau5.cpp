#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

struct Book{
    char id[20];
    char title[100];
    int year;
};

void findOldestBook(char* filePath){
    ifstream fin;

    fin.open(filePath);

    if (fin.is_open() == false){
        cout << "Khong the mo file\n";
        return;
    }
    
    char line[1000];
    Book ds[1000];
    int idx = 0;

    while (fin.getline(line, 1000)){
        char* id = strtok(line, ",");
        char* title = strtok(NULL, ",");
        char* yearS = strtok(NULL, ",");

        if (id && title && yearS){
            int year = atoi(yearS);
            strcpy(ds[idx].id, id);
            strcpy(ds[idx].title, title);
            ds[idx].year = year;

            idx++;
        }
    }

    if (idx == 0) return;

    int yearMin = ds[0].year;
    Book min = ds[0];
    for (int i = 0; i < idx; i++){
        if (ds[i].year < yearMin){
            yearMin = ds[i].year;
            min = ds[i];
        }
    }

    cout << min.title << " - Nam: " << min.year << endl;

    fin.close();
}