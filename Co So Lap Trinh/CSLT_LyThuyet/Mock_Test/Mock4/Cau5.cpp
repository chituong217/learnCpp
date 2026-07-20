#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

int countFailedAccess(char* filePath){
    int cnt = 0;

    ifstream fin;

    fin.open(filePath);

    if (fin.is_open() == false){
        cout << "Khong the mo file" << endl;
        return 0;
    }

    char line[1000];

    while (fin.getline(line, 1000)){
        char* ip = strtok(line, "-");
        char* date = strtok(NULL, "-");
        char* status = strtok(NULL, "-");
        
        if (ip && date && status){
            if (strstr(status, "FAIL") != NULL || strstr(status, "ERROR") != NULL){
                cnt++;
            }
        }
    }

    fin.close();
    return cnt;
}
