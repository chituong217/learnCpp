#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

struct Laptop{
    char* maSKU;
    char* tenMay;
    char* hangSX;
    int ram;
    long long giaTien;
};

struct Node{
    Laptop* data;
    Node* pNext;
};

struct KhoHang{
    Node* pHead;
    Node* pTail;
};

// cau 1
bool IsValidSKU(const char* sku){
    bool ok = true;
    if (strlen(sku) != 5 || isupper(sku[0]) == false || isupper(sku[1]) == false || isdigit(sku[2]) == false || isdigit(sku[3]) == false || isdigit(sku[4]) == false){
        ok = false;
    }

    return ok;
}

// cau 2
char* ExtractBrand(const char* tenMay){
    if (tenMay == NULL){
        return NULL;
    }

    char line[1000];
    strcpy(line, tenMay);
    
    char* word = strtok(line, " ");
    char* firstWord = new char[1000];
    strcpy(firstWord, word);

    return firstWord;
}

// cau 3
Laptop* CreateLaptop(const char* inputStr){
    if (inputStr == NULL){
        return NULL;
    }
    
    char line[1000];
    strcpy(line, inputStr);

    char* id = strtok(line, "/");
    if (IsValidSKU(id) == false){
        return NULL;
    }

    char* tenmay = strtok(NULL, "/");
    char* ramS = strtok(NULL, "/");
    char* giatienS = strtok(NULL, "/");

    if (id && tenmay && ramS && giatienS){
        Laptop* newLaptop = new Laptop;
        newLaptop->maSKU = new char[1000];
        newLaptop->tenMay = new char[1000];
        
        int ram = atoi(ramS);
        long long giatien = atoll(giatienS);

        strcpy(newLaptop->maSKU, id);
        strcpy(newLaptop->tenMay, tenmay);
        newLaptop->giaTien = giatien;
        newLaptop->ram = ram;
        newLaptop->hangSX = ExtractBrand(newLaptop->tenMay);

        int len = strlen(newLaptop->tenMay);
        for (int i = 0; i < len; i++){
            newLaptop->tenMay[i] = toupper(newLaptop->tenMay[i]);
        }
        return newLaptop;
    }

    return NULL;
}

// cau 4
char* LaptopToString(const Laptop* pLap){
    if (pLap == NULL){
        return NULL;
    }
    
    char* line = new char[1000];
    sprintf(line, "[%s] %s - RAM: %d GB (Gia: %lld)", pLap->maSKU, pLap->tenMay, pLap->ram, pLap->giaTien);

    return line;
}

// ham tao node
Node* createNode(Laptop* laptop){
    Node* newNode = new Node;
    newNode->data = laptop;
    newNode->pNext = NULL;

    return newNode;
}

// ham tao list
KhoHang createList(){
    KhoHang list;
    list.pHead = list.pTail = NULL;

    return list;
}

// ham add tail
void addTail(KhoHang &list, Laptop* laptop){
    Node* newNode = createNode(laptop);

    if (list.pHead == NULL){
        list.pHead = newNode;
        list.pTail = list.pHead;
    }
    else{
        list.pTail->pNext = newNode;
        list.pTail = list.pTail->pNext;
    }
}

// cau 5
void LoadData(const char* filename, KhoHang &list){
    ifstream fin;
    
    fin.open(filename);

    if (fin.is_open() == false){
        cout << "Khong the mo file" << endl;
        return;
    }

    char line[1000];

    while (fin.getline(line, 1000)){
        Laptop* newLaptop = CreateLaptop(line);
        if (newLaptop != NULL){
            addTail(list, newLaptop);
        }
    }

    fin.close();
}

// cau 6
void FreeList(KhoHang &list){
    if (list.pHead == NULL){
        return;
    }

    Node* tmp = list.pHead;
    while (tmp != NULL){
        delete []tmp->data->maSKU;
        delete []tmp->data->hangSX;
        delete []tmp->data->tenMay;
        delete tmp->data;

        Node* del = tmp;
        tmp = tmp->pNext;

        delete del;
    }

    list.pHead = list.pTail = NULL;
}

// cau 7
void DiscountByBrand(KhoHang &list, const char* brand, float percent){
    if (list.pHead == NULL){
        return;
    }

    Node* tmp = list.pHead;
    while (tmp != NULL){
        if (strcmp(tmp->data->hangSX, brand) == 0){
            tmp->data->giaTien *= (1 - percent);
        }

        tmp = tmp->pNext;
    }
}

// cau 8
void PrintList(KhoHang list){
    if (list.pHead == NULL){
        return;
    }

    Node* tmp = list.pHead;
    while (tmp != NULL){
        char* line = LaptopToString(tmp->data);
        cout << line << endl;

        delete []line;
        tmp = tmp->pNext;
    }
}

// tim max ram
void findandprintMaxRamLaptop(KhoHang list){
    if (list.pHead == NULL){
        return;
    }

    int maxRam = 0;
    Node* tmp = list.pHead;
    while (tmp != NULL){
        if (tmp->data->ram > maxRam){
            maxRam = tmp->data->ram;
        }
        tmp = tmp->pNext;
    }

    tmp = list.pHead;
    while (tmp != NULL){
        if (tmp->data->ram == maxRam){
            char* line = LaptopToString(tmp->data);
            cout << line << endl;

            delete []line;
        }
        
        tmp = tmp->pNext;
    }
}

int main(){
    KhoHang list = createList();

    LoadData("khohang.txt", list);

    cout << "--- KHO HANG GOC ---" << endl;
    PrintList(list);

    findandprintMaxRamLaptop(list);

    DiscountByBrand(list, "Asus", 0.15);
    cout << "--- SAU KHI GIAM GIA ASUS ---" << endl;
    PrintList(list);

    FreeList(list);

    return 0;
}