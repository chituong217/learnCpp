#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <ctime>

using namespace std;

struct SinhVien{
    char* masV;
    char* hoTen;
    float* diemMonHoc;
    int soMonHoc;
    float diemTB;
};

struct Option{
    float min, max;
};

struct Node{
    SinhVien* sv;
    Node* next;
};

struct ListSV{
    Node* head;
};

// cau 1
float GenerateRandom(const Option &opt){
    int min = (int)ceil(opt.min * 8);
    int max = (int)floor(opt.max * 8);
    int nguyen = min + rand() % (max - min + 1);

    float result = (float)nguyen * 0.125;
    return result;
}

// cau 2
void ChuanHoaHT(char* &ht){
    char line[1000];
    char res[1000] = "";
    strcpy(line, ht);
    
    char* token = strtok(line, " ");
    while (token != NULL){
        strcat(res, token);
        token = strtok(NULL, " ");

        if (token != NULL){
            strcat(res, " ");
        }
    }

    strcpy(ht, res);
}

// cau 3
SinhVien* CreateSV(const char *strIn){
    SinhVien* sv = new SinhVien;
    char* pName = new char[1000];
    char* pId = new char[1000];
    sv->hoTen = pName;
    sv->masV = pId;
    sv->diemMonHoc = NULL;

    char line[1000];
    strcpy(line, strIn);

    char* masV = strtok(line, ";");
    char* name = strtok(NULL, ";");
    char* somonhoc = strtok(NULL, ";");

    if (masV && name && somonhoc){
        int somonhocI = atoi(somonhoc);
        ChuanHoaHT(name);

        strcpy(pId, masV);
        strcpy(pName, name);
        sv->soMonHoc = somonhocI;

        // khoi tao mang monhoc de tinh diem tb
        float* monhoc = new float[1000];
        int n = somonhocI;
        sv->diemMonHoc = monhoc;

        Option diem;
        diem.max = 10.0;
        diem.min = 1.0;

        for (int i = 0; i < n; i++){
            monhoc[i] = GenerateRandom(diem);
        }

        float gpa = 0.0;
        for (int i = 0; i < n; i++){
            gpa += monhoc[i];
        }

        gpa /= 1.0 * n;
        sv->diemTB = gpa;
    }

    return sv;
}

// cau 4
char* SinhVienToString(const SinhVien *pSV){
    char* strSV = new char[1000];
    char line[1000] = "";
    sprintf(line, "%s (%s): %.3f", pSV->hoTen, pSV->masV, pSV->diemTB);
    strcpy(strSV, line);
    
    return strSV;
}

// ham khoi tao node

Node* makeNode(SinhVien* sv){
    Node* newNode = new Node;
    newNode->sv = sv;
    newNode->next = NULL;

    return newNode;
}

// cau 5

ListSV* Load(const char *path){
    ifstream fin;
    fin.open(path);

    if (fin.is_open() == false){
        return NULL;
    }

    ListSV* list = new ListSV;
    list->head = NULL;
    Node* tmp = list->head;

    char line[1000];
    while (fin.getline(line, 1000)){
        SinhVien* sv = CreateSV(line);
        if (tmp == NULL){
            list->head = makeNode(sv);
            tmp = list->head;
        }
        else{
            tmp->next = makeNode(sv);
            tmp = tmp->next;
        }
    }

    fin.close();
    return list;
}

// cau 6
void FreeData(ListSV *listSV){
    Node* tmp = listSV->head;

    while (tmp != NULL){
        delete []tmp->sv->masV;
        delete []tmp->sv->hoTen;
        delete []tmp->sv->diemMonHoc;
        delete tmp->sv;

        Node* del = tmp;
        tmp = tmp->next;
        
        delete del;
    }
    delete listSV;
}

// ham so sanh ten
bool comparebyname(SinhVien* a, SinhVien* b){
    if (strcmp(a->hoTen, b->hoTen) <= 0){
        return false;
    }
    else{
        return true;
    }
}

// ham so sanh diem trung binh
bool comparebygpa(SinhVien* a, SinhVien* b){
    if (a->diemTB <= b->diemTB){
        return false;
    }
    else{
        return true;
    }
}


// ham sap xep
void sapxepsinhvien(ListSV *list, bool(*compare)(SinhVien* a, SinhVien* b)){
    for (Node* i = list->head; i != NULL; i = i->next){
        Node* min = i;
        for (Node* j = i->next; j != NULL; j = j->next){
            if (compare(i->sv, j->sv) == true){
                min = j;
            }
        }
        SinhVien* tmp = min->sv;
        min->sv = i->sv;
        i->sv = tmp;
    }
}

// cau 7
void PrintData(ListSV *listSV){
    sapxepsinhvien(listSV, comparebyname);
    Node* tmp = listSV->head;

    while (tmp != NULL){
        cout << SinhVienToString(tmp->sv) << endl;
    }
}

// cau 8

SinhVien* copysinhvien(SinhVien* src){
    SinhVien* des = new SinhVien;
    des->masV = new char[1000];
    strcpy(des->masV, src->masV);
    des->hoTen = new char[1000];
    strcpy(des->hoTen, src->hoTen);
    des->diemTB = src->diemTB;
    des->soMonHoc = src->soMonHoc;

    des->diemMonHoc = new float[1000];
    for (int i = 0; i < des->soMonHoc; i++){
        des->diemMonHoc[i] = src->diemMonHoc[i];
    }

    return des;
}

ListSV* ExtractListSV(ListSV* list){
    ListSV* listA = new ListSV;
    listA->head = NULL;

    Node* tmp = list->head;
    Node* tmpA = listA->head;

    while (tmp != NULL){
        bool ok = false;
        int n = tmp->sv->soMonHoc;
        for (int i = 0; i < n; i++){
            if (tmp->sv->diemMonHoc[i] >= 7.0){
                ok = true;
            }
        }

        if (ok == true){
            // copy sinh vien o day
            SinhVien* sv = copysinhvien(tmp->sv);
            if (tmpA == NULL){
                listA->head = makeNode(sv);
                tmpA = listA->head;
            }
            else{
                tmpA->next = makeNode(sv);
                tmpA = tmpA->next;
            }
        }
        
        tmp = tmp->next;
    }
    sapxepsinhvien(listA, comparebygpa);

    return listA;
}

void PrintList(ListSV* list){
    Node* tmp = list->head;

    while (tmp != NULL){
        cout << SinhVienToString(tmp->sv) << endl;
    }
}

int main(){
    srand(time(NULL));
    const char* path = "data.txt";
    ListSV *listSV = Load(path);
    PrintData(listSV);
    cout << endl << endl;

    ListSV *listSV_A = ExtractListSV(listSV);
    PrintList(listSV_A);

    FreeData(listSV);
    FreeData(listSV_A);
    return 0;
}

