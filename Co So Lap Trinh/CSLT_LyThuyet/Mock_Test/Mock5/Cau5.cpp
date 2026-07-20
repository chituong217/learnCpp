#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

struct Product{
    char id[20];
    char name[50];
    int quantity;
    long long importPrice;
    long long sellPrice;
};

void findBestProfitProduction(char* pathFile){
    Product bestProduct;
    long long maxProfit = 0;

    ifstream fin;

    fin.open(pathFile);

    if (fin.is_open() == false){
        cout << "Khong the mo file\n";
        return;
    }

    char line[1000];
    
    while (fin.getline(line, 1000)){
        char* id = strtok(line, ",");
        char* name = strtok(NULL, ",");
        char* quantity = strtok(NULL, ",");
        char* importPrice = strtok(NULL, ",");
        char* sellPrice = strtok(NULL, ",");

        if (id && name && quantity && importPrice && sellPrice){
            int quantityI = atoi(quantity);
            long long importPriceLL = atoll(importPrice);
            long long sellPriceLL = atoll(sellPrice);

            Product nowProduct;
            strcpy(nowProduct.id, id);
            strcpy(nowProduct.name, name);
            nowProduct.quantity = quantityI;
            nowProduct.importPrice = importPriceLL;
            nowProduct.sellPrice = sellPriceLL;

            long long profit = (sellPriceLL - importPriceLL) * quantityI;
            if (profit > maxProfit){
                bestProduct = nowProduct;
                maxProfit = profit;
            }
        }
    }

    fin.close();
    cout << bestProduct.id << " - " << bestProduct.name << " - " << bestProduct.quantity << " - " << bestProduct.importPrice << " - " << bestProduct.sellPrice << endl;
}