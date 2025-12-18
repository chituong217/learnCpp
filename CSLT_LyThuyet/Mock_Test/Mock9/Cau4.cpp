#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

struct Product{
    char id[11];
    char name[51];
    long long price;
    int quantity;
};

void filterHighValueProducts(char* inputFileName, char* outputFileName, long long minPrice){
    ifstream fin;
    ofstream fout;

    fin.open(inputFileName);
    fout.open(outputFileName);

    if (fin.is_open() == false){
        cout << "Khong the doc file" << endl;
        return;
    }
    if (fout.is_open() == false){
        cout << "Khong the ghi file" << endl;
        return;
    }

    char line[1000];

    while (fin.getline(line, 1000)){
        char* id = strtok(line, ",");
        char* name = strtok(NULL, ",");
        char* priceS = strtok(NULL, ",");
        char* quantityS = strtok(NULL, ",");

        if (id && name && priceS && quantityS){
            long long price = atoll(priceS);
            int quantity = atoi(quantityS);

            if (price >= minPrice){
                long long sell = price * quantity;
                fout << id << "," << name << "," << price << "," << quantity << "," << sell << endl;
            }
        }
    }

    fout.close();
    fin.close();
}