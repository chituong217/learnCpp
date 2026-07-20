#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

struct TepTin{
    char* tenFile;
    char* phanMoRong;
    long long kichThuoc;
    char* ngayTao;
};

struct Node{
    TepTin* data;
    Node* pNext;
};

struct ThuMuc{
    Node* pHead;
    Node* pTail;
};

// cau 1
long long RandomSize(long long min, long long max){
    long long res = min + rand() % (max - min + 1);
    
    return res;
}

// cau 2
char* GetExtension(const char* tenFile){
    if (tenFile == NULL){
        return NULL;
    }
    
    char line[1000];
    strcpy(line, tenFile);

    char *res = new char[100];
    char* token = strtok(line, ".");
    while (token != NULL){
        strcpy(res, token);

        token = strtok(NULL, ".");
    }

    return res;
}

// cau 3
TepTin* CreateTepTin(const char* inputStr){
    if (inputStr == NULL){
        return NULL;
    }

    char line[1000];
    strcpy(line, inputStr);

    char* ten = strtok(line, "|");
    char* kichthuoc = strtok(NULL, "|");
    char* ngaytao = strtok(NULL, "|");

    if (ten && kichthuoc && ngaytao){
        TepTin* newFile = new TepTin;

        newFile->phanMoRong = GetExtension(ten);
        
        newFile->kichThuoc = atoll(kichthuoc);
        
        newFile->ngayTao = new char[20];
        strcpy(newFile->ngayTao, ngaytao);

        newFile->tenFile = new char[1000];
        strcpy(newFile->tenFile, ten);

        return newFile;
    }

    return NULL;
}

// cau 4
char* TepTinToString(const TepTin* pFile){
    if (pFile == NULL){
        return NULL;
    }

    char* line = new char[1000];

    if (pFile->kichThuoc > 1024){
        long long kichthuocKB = pFile->kichThuoc / 1024;
        sprintf(line, "[%s] %s - %lldKB - %s", pFile->phanMoRong, pFile->tenFile, kichthuocKB, pFile->ngayTao);
    }
    else{
        sprintf(line, "[%s] %s - %lld Bytes - %s", pFile->phanMoRong, pFile->tenFile, pFile->kichThuoc, pFile->ngayTao);
    }

    return line;
}

// ham khoi tao node
Node* createNode(TepTin* file){
    if (file == NULL){
        return NULL;
    }

    Node* newNode = new Node;
    newNode->data = file;
    newNode->pNext = NULL;
    
    return newNode;
}

// ham khoi tao list
void InitList(ThuMuc &list){
    list.pHead = list.pTail = NULL;

}

// ham add tail
void addTail(ThuMuc &list, TepTin* file){
    Node* newNode = createNode(file);

    if (list.pHead == NULL){
        list.pHead = newNode;
        list.pTail = newNode;
    }
    else{
        list.pTail->pNext = newNode;
        list.pTail = newNode;
    }
}

// cau 5
void LoadData(const char* filename, ThuMuc &list){
    ifstream fin;

    fin.open(filename);

    if (fin.is_open() == false){
        cout << "Khong the mo file" << endl;
        return;
    }

    char line[1000];

    while (fin.getline(line, 1000)){
        TepTin* newFile = CreateTepTin(line);
        
        if (newFile != NULL){
            addTail(list, newFile);
        }
    }

    fin.close();
}

// cau 6
void FreeList(ThuMuc &list){
    if (list.pHead == NULL){
        return;
    }

    Node* tmp = list.pHead; 
    while (tmp != NULL){
        delete []tmp->data->ngayTao;
        delete []tmp->data->phanMoRong;
        delete []tmp->data->tenFile;
        
        delete tmp->data;
        Node* del = tmp;

        tmp = tmp->pNext;
        delete del;
    }

    list.pHead = list.pTail = NULL;
}

// cau 7
void SortFiles(ThuMuc &list, int (*compareFunc)(TepTin* a, TepTin* b)){
    for (Node* i = list.pHead; i != NULL; i = i->pNext){
        Node* best = i;
        for (Node* j = i->pNext; j != NULL; j = j->pNext){
            if (compareFunc(best->data, j->data) > 0){
                best = j;
            }
        }

        TepTin* tmp = best->data;
        best->data = i->data;
        i->data = tmp;
    }
}

// cau 8
int CompareBySizeAcs(TepTin* a, TepTin* b){
    if (a->kichThuoc > b->kichThuoc){
        return 1;
    }
    else if (a->kichThuoc < b->kichThuoc){
        return -1;
    }
    else{
        return 0;
    }
}

int CompareByNameDesc(TepTin* a, TepTin* b){
    int cmp = strcmp(a->tenFile, b->tenFile);

    if (cmp > 0){
        return -1;
    }
    else if (cmp < 0){
        return 1;
    }
    else{
        return 0;
    }
}

// ham print list
void PrintList(ThuMuc list){
    if (list.pHead == NULL){
        return;
    }

    Node* tmp = list.pHead;
    while (tmp != NULL){
        char* del = TepTinToString(tmp->data);
        cout << del << endl;
        delete []del;

        tmp = tmp->pNext;
    }
}

int main(){
    srand(time(NULL));

    ThuMuc list;
    InitList(list);

    LoadData("files.txt", list);

    cout << "--- DANH SACH GOC ---" << endl;
    PrintList(list);
    
    SortFiles(list, CompareBySizeAcs);
    cout << "--- SAP XEP THEO SIZE (TANG) ---" << endl;
    PrintList(list);

    SortFiles(list, CompareByNameDesc);
    cout << "--- SAP XEP THEO TEN (GIAM) ---" << endl;
    PrintList(list);

    FreeList(list);
    
    return 0;
}