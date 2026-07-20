#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cctype>

using namespace std;

void findProducts(char* filePath, char* keyword){
    ifstream fin;
    fin.open(filePath);
    if (!fin.is_open()){
        cout << "Khong the mo file" << endl;
        return;
    }
    char line[1000];
    while(fin.getline(line, 1000)){
        char* id = strtok(line, ",");
        char* name = strtok(NULL, ",");
        char* price = strtok(NULL, ",");
        if (strstr(name, keyword) != NULL){
            cout << id << ";;" << name << ";;" << price << endl;
        }
    }
    fin.close();
}

int main(){

    return 0;
}