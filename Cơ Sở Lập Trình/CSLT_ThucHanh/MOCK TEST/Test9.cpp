#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <cstdio>

using namespace std;

struct SinhVien{
    char* maSV;
    char* hoTen;
    float diem[3];
    float diemtb;
};

struct Node{
    SinhVien* data;
    Node* pNext;
};

struct ListSV{
    Node* pHead;
    Node* pTail;
};

// cau 1
float TinhDTB(float diem[]){
    float gpa = 0;
    for (int i = 0; i < 3; i++){
        gpa += diem[i];
    }

    gpa /= 3.0;

    return gpa;
}

// cau 2
char* GetTen(const char* hoTenDayDu){
    if (hoTenDayDu == NULL){
        return NULL;
    }

    char* res = new char[100];
    char line[1000];
    strcpy(line, hoTenDayDu);

    char* token = strtok(line, " ");
    while (token != NULL){
        strcpy(res, token);

        token = strtok(NULL, " ");
    }

    return res;
}

// cau 3
SinhVien* CreateSinhVien(const char* inputStr){
    if (inputStr == NULL){
        return NULL;
    }

    char line[1000];
    strcpy(line, inputStr);

    char* mssv = strtok(line, ";");
    char* hoten = strtok(NULL, ";");
    char* toan = strtok(NULL, ";");
    char* ly = strtok(NULL, ";");
    char* hoa = strtok(NULL, ";");

    if (mssv && hoten && toan && ly && hoa){
        SinhVien* sv = new SinhVien;

        sv->hoTen = new char[1000];
        strcpy(sv->hoTen, hoten);

        sv->maSV = new char[100];
        strcpy(sv->maSV, mssv);

        sv->diem[0] = atof(toan);
        sv->diem[1] = atof(ly);
        sv->diem[2] = atof(hoa);

        sv->diemtb = TinhDTB(sv->diem);

        return sv;
    }

    return NULL;
}

// cau 4
char* SVToString(const SinhVien* sv){
    if (sv == NULL){
        return NULL;
    }

    char* line = new char[1000];
    sprintf(line, "[%s] %s - Toan: %.2f, Ly: %.2f, Hoa: %.2f (DTB: %.2f)", sv->maSV, sv->hoTen, sv->diem[0], sv->diem[1], sv->diem[2], sv->diemtb);

    return line;
}

// ham tao node
Node* createNode(SinhVien* sv){
    if (sv == NULL){
        return NULL;
    }

    Node* newNode = new Node;
    newNode->data = sv;
    newNode->pNext = NULL;

    return newNode;
}

// ham khoi tao list
void InitList(ListSV &list){
    list.pHead = list.pTail = NULL;
}

// ham add tail
void addTail(ListSV &list, SinhVien* sv){
    if (sv == NULL){
        return;
    }

    Node* newNode = createNode(sv);

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
void LoadData (const char* filename, ListSV &list){
    ifstream fin;

    fin.open(filename);

    if (fin.is_open() == false){
        cout << "Khong the mo file" << endl;
        return;
    }

    char line[1000];
    while (fin.getline(line, 1000)){
        SinhVien* newSV = CreateSinhVien(line);

        if (newSV != NULL){
            addTail(list, newSV);
        }
    }

    fin.close();
}

// cau 6
void FreeList(ListSV &list){
    if (list.pHead == NULL){
        return;
    }

    Node* tmp = list.pHead;
    while (tmp != NULL){
        delete []tmp->data->maSV;
        delete []tmp->data->hoTen;
        
        delete tmp->data;

        Node* del = tmp;

        tmp = tmp->pNext;
        delete del;
    }

    list.pHead = list.pTail = NULL;
}

// ham deepcopy
void deepCopy(SinhVien* src, SinhVien* des){
    if (src == NULL){
        des = NULL;
        return;
    }

    des->hoTen = new char[1000];
    strcpy(des->hoTen, src->hoTen);

    des->maSV = new char[100];
    strcpy(des->maSV, src->maSV);

    for (int i = 0; i < 3; i++){
        des->diem[i]  = src->diem[i];
    }

    des->diemtb = src->diemtb;
}

// cau 7
void ExtractScholarship(ListSV src, ListSV &des){
    if (src.pHead == NULL){
        return;
    }

    Node* tmp = src.pHead;
    while (tmp != NULL){
        bool isScholarship = true;

        if (tmp->data->diemtb < 8){
            isScholarship = false;
        }

        for (int i = 0; i < 3; i++){
            if (tmp->data->diem[i] < 5){
                isScholarship = false;
            }
        }

        if (isScholarship == true){
            SinhVien* newSV = new SinhVien;
            deepCopy(tmp->data, newSV);

            addTail(des, newSV);
        }

        tmp = tmp->pNext;
    }
}

void PrintList(ListSV list){
    if (list.pHead == NULL){
        return;
    }

    Node* tmp = list.pHead;
    while (tmp != NULL){
        char* del = SVToString(tmp->data);
        cout << del << endl;
        delete []del;

        tmp = tmp->pNext;
    }
}

// sap xep list tang dan theo ten, giam dan theo diem trbinh

int CompareSV (SinhVien *a, SinhVien *b){
    if (strcmp(a->hoTen, b->hoTen) > 0){
        return 1;
    }
    else if (strcmp(a->hoTen, b->hoTen) == 0){
        if (a->diemtb < b->diemtb){
            return 1;
        }
        else{
            return -1;
        }
    }
    else{
        return -1;
    }
}

// ham sort
void SortList(ListSV &list, int(*comp)(SinhVien *a, SinhVien *b)){
    for (Node* i = list.pHead; i != NULL; i = i->pNext){
        Node* best = i;
        for (Node* j = i->pNext; j != NULL; j = j->pNext){
            if (comp(best->data, j->data) > 0){
                best = j;
            }
        }

        SinhVien* tmp = best->data;
        best->data = i->data;
        i->data = tmp;
    }
}

int main(){
    ListSV list;
    InitList(list);
    LoadData("diemso.txt", list);

    cout << "--- DANH SACH GOC ---" << endl;
    PrintList(list);

    SortList(list, CompareSV);

    cout << "--- SAU KHI SAP XEP ---" << endl;
    PrintList(list);

    ListSV listHB;
    InitList(listHB);
    ExtractScholarship(list, listHB);

    cout << "--- DANH SACH HOC BONG ---" << endl;
    PrintList(listHB);

    FreeList(list);
    FreeList(listHB);

    return 0;
}
