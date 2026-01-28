#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

struct CauThu{
    char* maCauThu;
    char* hoTen;
    char* clb;
    int soAo;
    double giaTriCN;
};

struct Node{
    CauThu* data;
    Node* pNext;
};

struct ListCT{
    Node* pHead;
    Node* pTail;
};

// cau 1
double RandomGiaTri(double min, double max){
    double lMin = min / 0.5;
    double lMax = max / 0.5;

    double res = (int)lMin + (int)rand() % (int)(lMax - lMin + 1);
    res *= 0.5;

    return res;
}

// cau 2
void ChuanHoaChuoi(char* &str){
    if (str == NULL){
        return;
    }

    char line[1000];
    char res[1000] = "";
    strcpy(line, str);
    
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

    strcpy(str, res);
}

// cau 3
CauThu* CreateCauThu(const char* inputStr){
    if (inputStr == NULL){
        return NULL;
    }

    char line[1000];
    strcpy(line, inputStr);

    char* id = strtok(line, ";");
    char* name = strtok(NULL, ";");
    char* clb = strtok(NULL, ";");
    char* soAoS = strtok(NULL, ";");

    if (id && name && clb && soAoS){
        CauThu* newCT = new CauThu;
        newCT->maCauThu = new char[1000];
        newCT->hoTen = new char[1000];
        newCT->clb = new char[1000];

        strcpy(newCT->clb, clb);
        strcpy(newCT->hoTen, name);
        strcpy(newCT->maCauThu, id);

        ChuanHoaChuoi(newCT->clb);
        ChuanHoaChuoi(newCT->hoTen);

        int soAo = atoi(soAoS);
        newCT->soAo = soAo;

        newCT->giaTriCN = RandomGiaTri(10.0, 100.0);

        return newCT;
    }

    return NULL;
}

// cau 4
char* CauThuToString(const CauThu* pCT){
    if (pCT == NULL){
        return NULL;
    }

    char* line = new char[1000];
    sprintf(line, "[%s] %s - %s (Gia: %lfM Euro)", pCT->maCauThu, pCT->hoTen, pCT->clb, pCT->giaTriCN);

    return line;
}

// ham khoi tao node
Node* createNode(CauThu* cauthu){
    if (cauthu == NULL) return NULL;
    Node* newNode = new Node;
    newNode->data = cauthu;
    newNode->pNext = NULL;

    return newNode;
}

// ham khoi tao list
ListCT createList(){
    ListCT list;
    list.pHead = list.pTail = NULL;

    return list;
}

// ham add tail

void addTail(ListCT &list, CauThu* ct){
    Node* newNode = createNode(ct);

    if (list.pHead == NULL){
        list.pHead = newNode;
        list.pTail = list.pHead;
        return;
    }
    
    list.pTail->pNext = newNode;
    list.pTail = newNode;
}

// cau 5
void LoadData(const char* filename, ListCT &list){
    if (filename == NULL){
        return;
    }

    ifstream fin;

    fin.open(filename);

    if (fin.is_open() == false){
        cout << "Khong the mo file" << endl;
        return;
    }

    char line[1000];
    while (fin.getline(line, 1000)){
        CauThu* newCT = CreateCauThu(line);

        if (newCT != NULL){
            addTail(list, newCT);
        }
    }

    fin.close();
}

// cau 6
void FreeList(ListCT &list){
    if (list.pHead == NULL){
        return;
    }

    Node* tmp = list.pHead;
    while (tmp != NULL){
        delete []tmp->data->clb;
        delete []tmp->data->hoTen;
        delete []tmp->data->maCauThu;

        delete tmp->data;

        Node* del = tmp;

        tmp = tmp->pNext;

        delete del;
    }

    list.pHead = list.pTail = NULL;
}

// ham print List
void PrintList(ListCT list){
    if (list.pHead == NULL){
        return;
    }

    Node* tmp = list.pHead;
    while (tmp != NULL){
        char* del = CauThuToString(tmp->data);
        cout << del << endl;
        delete del;

        tmp = tmp->pNext;
    }
}

// ham comparator giam dan theo gia tri chuyen nhuong 
int compbygiaTriCN(CauThu* a, CauThu* b){
    if (a->giaTriCN < b->giaTriCN){
        return 1;
    }
    else if (a->giaTriCN == b->giaTriCN){
        return 0;
    }
    else{
        return -1;
    }
}

// ham comparator tang dan theo so ao
bool compbysoAo(CauThu* a, CauThu *b){
    if (a->soAo > b->soAo){
        return true;
    }
    else{
        return false;
    }
}

// ham sort theo 2 comp
void sortBy2Comp(ListCT &list, int (*comp1)(CauThu* a, CauThu* b), bool (*comp2)(CauThu* a, CauThu* b)){
    for (Node* i = list.pHead; i != NULL; i = i->pNext){
        Node* best = i;
        for (Node* j = i->pNext; j != NULL; j = j->pNext){
            if (comp1(best->data, j->data) == 1){
                best = j;
            }
            else if (comp1(best->data, j->data) == 0){
                if (comp2(best->data, j->data) == true){
                    best = j;
                }
            }
        }

        CauThu* tmp = best->data;
        best->data = i->data;
        i->data = tmp;
    }
}

// cau 7
void PrintSortedList(ListCT list){
    if (list.pHead == NULL){
        return;
    }

    sortBy2Comp(list, compbygiaTriCN, compbysoAo);
    PrintList(list);
}

// cau 8
void TransferPlayer(ListCT &list, const char* clbSRC, const char* clbDES){
    if (list.pHead == NULL){
        return;
    }

    Node* tmp = list.pHead;
    while (tmp != NULL){

        if (strcmp(tmp->data->clb, clbSRC) == 0){
            strcpy(tmp->data->clb, clbDES);
        }

        tmp = tmp->pNext;
    }
}

int main(){
    srand(time(NULL));

    ListCT list = createList();

    LoadData("cauthu.txt", list);

    cout << "--- DANH SACH CAU THU ---" << endl;
    PrintSortedList(list);

    TransferPlayer(list, "Chelsea", "Real Madrid");

    cout << "--- SAU KHI CHUYEN NHUONG ---" << endl;
    PrintList(list);

    FreeList(list);

    return 0;
}