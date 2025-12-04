#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

struct Order{
    char id[20];
    char name[100];
    int quantity;
    long long price;
};

void filterHighValueOrder(char* inputFile, char* outputFile){
    ifstream fin;
    ofstream fout;

    fin.open(inputFile);
    fout.open(outputFile);

    if (fin.is_open() == false || fout.is_open() == false){
        cout << "Khong the mo file\n";
        return;
    }

    char line[1000];
    while (fin.getline(line, 1000)){
        char* id = strtok(line, ",");
        char* name = strtok(NULL, ",");
        char* quantity = strtok(NULL, ",");
        char* price = strtok(NULL, ",");

        int quantityI = atoi(quantity);
        long long priceLL = atoll(price);
        long long sum = quantityI * priceLL;
        if (sum > 1000000){
            fout << id << " - " << name << " - " << "Tong: " << sum << endl;
        }
    }

    fout.close();
    fin.close();
}