#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <ctime>

using namespace std;

struct VeTau{
    char* maVe;
    char* tenKhach;
    int namSinh;
    char* loaiGhe;
    long long giaVe;
};

struct Node{
    VeTau* data;
    Node* next;
};

struct ListVe{
    Node* pHead;
};


// cau 1
char* GenerateRandomID(int length){
    char* id = new char[length + 1];
    for (int i = 0; i < length; i++){
        id[i] = (char)((int)'0' + rand() % ((int)'9' - (int)'0' + 1));
    }

    id[length] = '\0';

    return id;
}

// chuan hoa ten
void ChuanHoaTen(char* &hoten){
    if (hoten == NULL) {
        return;
    }

    char line[1000];
    strcpy(line, hoten);

    char res[1000] = "";

    char* token = strtok(line, " ");
    while (token != NULL){
        int len = strlen(token);
        for (int i = 0; i < len; i++){
            if (i == 0){
                token[i] = toupper(token[i]);
            }
            else{
                token[i] = tolower(token[i]);
            }
        }

        strcat(res, token);
        
        token = strtok(NULL, " ");
        
        if (token != NULL){
            strcat(res, " ");
        }
    }

    strcpy(hoten, res);
}

// cau 2
char* GetTen(const char* hoTenDayDu){
    char line[1000];
    strcpy(line, hoTenDayDu);
    char* res = new char[100];

    char* token = strtok(line, " ");
    while (token != NULL){
        strcpy(res, token);
        token = strtok(NULL, " ");
    }

    return res;
}

// cau 3
VeTau* CreateVeTau(const char* inputStr){
    if (inputStr == NULL){
        return NULL;
    }

    VeTau* newVeTau = new VeTau;
    newVeTau->loaiGhe = new char[1000];
    newVeTau->tenKhach = new char[1000];

    char line[1000];
    strcpy(line, inputStr);
    
    char* hoten = strtok(line, ",");
    char* namsinhS = strtok(NULL, ",");
    char* loaighe = strtok(NULL, ",");
    char* giaveS = strtok(NULL, ",");

    if (hoten && namsinhS && loaighe && giaveS){
        strcpy(newVeTau->tenKhach, hoten);
        strcpy(newVeTau->loaiGhe, loaighe);

        newVeTau->namSinh = atoi(namsinhS);
        newVeTau->giaVe = atoll(giaveS);

        newVeTau->maVe = GenerateRandomID(6);

        ChuanHoaTen(newVeTau->tenKhach);
        ChuanHoaTen(newVeTau->loaiGhe);
    }

    return newVeTau;
}

// cau 4
char* VeTauToString(const VeTau* pVe){
    if (pVe == NULL){
        return NULL;
    }
    
    char* line = new char[1000];

    sprintf(line, "[%s] %s (%d) - Loai Ghe: %s %lld VND", pVe->maVe, pVe->tenKhach, pVe->namSinh, pVe->loaiGhe, pVe->giaVe);

    return line;
}


// Tao node
Node* createNode(VeTau* ve){
    Node* newNode = new Node;
    newNode->data = ve;
    newNode->next = NULL;

    return newNode;
}

// Tao list
ListVe createList(){
    ListVe list;
    list.pHead = NULL;

    return list;
}

// Add head list
void addHeadList(ListVe &list, VeTau* ve){
    Node* newNode = createNode(ve);
    if (list.pHead == NULL){
        list.pHead = newNode;
        return;
    }
    
    newNode->next = list.pHead;
    list.pHead = newNode;
}

// cau 5
void LoadDataHead(const char* fileName, ListVe &list){
    ifstream fin;

    fin.open(fileName);

    if (fin.is_open() == false){
        cout << "Ko the mo file" << endl;
        return;
    }

    char line[1000];
    while (fin.getline(line, 1000)){
        VeTau* ve = CreateVeTau(line);
        addHeadList(list, ve);
    }

    fin.close();
}

// cau 6
void FreeList(ListVe &list){
    if (list.pHead == NULL){
        return;
    }

    Node* tmp = list.pHead;
    while (tmp != NULL){
        delete []tmp->data->loaiGhe;
        delete []tmp->data->maVe;
        delete []tmp->data->tenKhach;
        delete tmp->data;

        Node* del = tmp;
        tmp = tmp->next;

        delete del;
    }

    list.pHead = NULL;
}

void RemoveVeByPrice (ListVe &list, long long priceX){
    if (list.pHead == NULL){
        return;
    }
    
    Node dummy;
    Node* tail = &dummy;

    Node* tmp = list.pHead;
    while (tmp != NULL){
        if (tmp->data->giaVe >= priceX){
            tail->next = tmp;
            tail = tail->next;
            tmp = tmp->next;
        }
        else{
            Node* del = tmp;
            tmp = tmp->next;

            delete []del->data->loaiGhe;
            delete []del->data->maVe;
            delete []del->data->tenKhach;
            delete del->data;
            delete del;
        }
    }
    
    tail->next = NULL;

    list.pHead = dummy.next;
}

// cau 8

void PrintList(ListVe list){
    if (list.pHead == NULL){
        return;
    }

    Node* tmp = list.pHead;
    while (tmp != NULL){
        char* tmpString = VeTauToString(tmp->data);
        cout << tmpString << endl;

        tmp = tmp->next;
        delete []tmpString;
    }
}

long long tinhTongGiaVe(ListVe list){
    if (list.pHead == NULL){
        return 0;
    }

    long long sum = 0;

    Node* tmp = list.pHead;
    while (tmp != NULL){
        if (strcmp(tmp->data->loaiGhe, "Giuong Nam") == 0){
            sum += tmp->data->giaVe;
        }
        tmp = tmp->next;
    }

    return sum;
}

int main(){
    srand(time(NULL));

    ListVe list = createList();

    LoadDataHead("data.txt", list);

    cout << "--- DANH SACH BAN DAU ---" << endl;
    PrintList(list);

    cout << tinhTongGiaVe(list) << endl;

    
    cout << "--- DANG XOA VE GIA RE (< 100k) ---" << endl;
    RemoveVeByPrice(list, 100000);
    PrintList(list);

    FreeList(list);
    return 0;
}