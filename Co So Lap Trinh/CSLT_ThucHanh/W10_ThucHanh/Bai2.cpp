#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

struct SinhVien{
    char hoten[31];
    char mssv[9];
    float diemtrungbinh;
};

struct Node{
    SinhVien* data;
    Node* next;
};

struct List{
    Node* head;
};

// cau 1
List createList(){
    List list;
    list.head = NULL;
    return list; 
}

// ham khoi tao node
Node* createNode(SinhVien* data){
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// cau 2
void addHead(List &list, SinhVien *sv){
    Node* newNode = createNode(sv);

    if (list.head == NULL){
        list.head = newNode;
        return;    
    }

    newNode->next = list.head;
    list.head = newNode;
}

// cau 3

void printHoTenSinhVien(SinhVien *sv){
    cout << "Ten: " << sv->hoten << endl;
}

void printHoTenVaMSSV(SinhVien *sv){
    cout << "Ten :" << sv->hoten << " MSSV: " << sv->mssv << endl;
}

void printThongTinSV(SinhVien *sv){
    cout << "Ten :" << sv->hoten << " MSSV: " << sv->mssv << " Diem trung binh: " << sv->diemtrungbinh << endl;
}

// ham duyet su dung con tro ham
void duyetListvaThucThi(List list, void(*task)(SinhVien* sv)){
    Node* tmp = list.head;
    while (tmp != NULL){
        task(tmp->data);
        tmp = tmp->next;
    }
}

// cau 4

// gia su file co dinh dang
// <mssv>,<ten>,<diemtrungbinh>
// va ko co dong nao loi

// ham doc file
void docLopHocTuFile(const char* filePath, List &list){
    ifstream fin;

    fin.open(filePath);

    if (fin.is_open() == false){
        cout << "Khong the mo file input" << endl;
        return;
    }

    char line[1000];
    while (fin.getline(line, 1000)){
        char* id = strtok(line, ",");
        char* ten = strtok(NULL, ",");
        char* gpaS = strtok(NULL, ",");

        if (id && ten && gpaS){
            SinhVien* newSV = new SinhVien;
            
            float gpa = atof(gpaS);
            strcpy(newSV->mssv, id);
            strcpy(newSV->hoten, ten);
            newSV->diemtrungbinh = gpa;

            addHead(list, newSV);
        }
    }

    fin.close();
}

// ham ghi file
void ghiLopHocVaoFile(List list, const char* filePath){
    ofstream fout;

    fout.open(filePath);

    if (fout.is_open() == false){
        cout << "Khong the mo file output" << endl;
        return;
    }

    if (list.head == NULL){
        return;
    }

    Node* tmp = list.head;
    while (tmp != NULL){
        fout << "Ten :" << tmp->data->hoten << " MSSV: " << tmp->data->mssv << " Diem trung binh: " << tmp->data->diemtrungbinh << endl;
        tmp = tmp->next;
    }

    fout.close();
}

// cau 5 

// false la be hon, true la lon hon
bool compbymssv(SinhVien* a, SinhVien* b){
    if (strcmp(a->mssv, b->mssv) <= 0){
        return false;
    }
    else{
        return true;
    }
}

bool compbyhoten(SinhVien* a, SinhVien* b){
    if (strcmp(a->hoten, b->hoten) <= 0){
        return false;
    }
    else{
        return true;
    }
}

bool compbydiemtrungbinh(SinhVien*a, SinhVien *b){
    if (a->diemtrungbinh <= b->diemtrungbinh){
        return false;
    }
    else{
        return true;
    }
}

void sortLopHoc(List &list, bool(*comp)(SinhVien* a, SinhVien* b)){
    for (Node* i = list.head; i != NULL; i = i->next){
        Node* min = i;
        for (Node* j = i->next; j != NULL; j = j->next){
            if (comp(min->data, j->data) == true){
                min = j;
            }
        }

        SinhVien* tmp = min->data;
        min->data = i->data;
        i->data = tmp;
    }
}

// cau 6

void duoihocSinhVienTheoMSSV(List &list, char id[]){
    if (list.head == NULL){
        return;
    }

    Node* prev = NULL;
    Node* tmp = list.head;
    while (tmp != NULL){
        if (strcmp(tmp->data->mssv, id) == 0){
            Node* del = tmp;
            if (tmp == list.head){
                list.head = list.head->next;
            }
            else{
                prev->next = tmp->next;
            }
            tmp = tmp->next;

            delete del->data;
            delete del;
        }
        else{
            prev = tmp;
            tmp = tmp->next;
        }
    }
}

void duoihocSinhVienGPABelow5(List &list){
    if (list.head == NULL){
        return;
    }

    Node* prev = NULL;
    Node* tmp = list.head;
    while (tmp != NULL){
        if (tmp->data->diemtrungbinh < 5){
            Node* del = tmp;

            if (tmp == list.head){
                list.head = list.head->next;
            }
            else{
                prev->next = tmp->next;
            }
            tmp = tmp->next;

            delete del->data;
            delete del;
        }
        else{
            prev = tmp;
            tmp = tmp->next;
        }
    }
}

// cau 7
void deleteList(List &list){
    if (list.head == NULL){
        return;
    }

    Node* tmp = list.head;
    while (tmp != NULL){
        Node* del = tmp;
        delete tmp->data;
        tmp = tmp->next;

        delete del;
    }

    list.head = NULL;
}

// cau 8
// do de ko ro rang, theo em hieu la
// cho 1 list da duoc sap xep theo 1
// tieu chi cu the, can them 1 sv vao list
// sao cho list van giu nguyen tinh chat don dieu ban dau


// em se mac dinh la list duoc sap xep tang dan

void addAscendingList(List &list, SinhVien* sv, bool(*tieuchi)(SinhVien *a, SinhVien *b)){
    if (list.head == NULL || tieuchi(sv, list.head->data) == true){
        addHead(list, sv);
        return;
    }

    Node* newNode = createNode(sv);
    Node* tmp = list.head;
    while (tmp != NULL){
        if (tieuchi(tmp->data, sv) == true){
            if (tmp->next == NULL){
                tmp->next = newNode;
                return;
            }
            else{
                Node* next = tmp->next;
                if (tieuchi(sv, next->data) == true){
                    newNode->next = next;
                    tmp->next = newNode;                 
                }
            }
        }

        tmp = tmp->next;
    }
}

// cau 9
// gia su lop 1 va lop 2 duoc khoi tao rong
void tachLopHoc(List &list, List &lop1, List &lop2){
    if (list.head == NULL){
        return;
    }

    int n = 0;
    Node* tmp = list.head;
    while (tmp != NULL){
        tmp = tmp->next;
        n++;
    }

    int middle_pos = (n/2);
    if (n % 2 == 0){
        middle_pos--;
    }

    Node* tail1 = list.head;
    for (int i = 0; i < middle_pos; i++){
        tail1 = tail1->next;
    }

    lop1.head = list.head;
    lop2.head = tail1->next;
    tail1->next = NULL;

    list.head = NULL;
}

// cau 10
void gopLopHoc(List &list, List &lop1, List &lop2){
    if (lop1.head == NULL && lop2.head == NULL){
        list.head = NULL;
        return;
    }
    else if (lop1.head == NULL){
        list.head = lop2.head;
        lop2.head = NULL;
        return;
    }
    else if (lop2.head == NULL){
        list.head = lop1.head;
        lop1.head = NULL;
        return;
    }

    list.head = lop1.head;

    Node *tail = list.head;
    while (tail->next != NULL){
        tail = tail->next;
    }

    tail->next = lop2.head;

    lop1.head = NULL;
    lop2.head = NULL;
}
