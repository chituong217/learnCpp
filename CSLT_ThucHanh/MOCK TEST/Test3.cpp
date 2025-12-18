#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <ctime>
#include <cstdlib>

using namespace std;

struct NhanVien{
    char* maNV;
    char* hoTen;
    char* phongBan;
    int luongCoBan;
    float heSoHieuQua;
};

struct Node{
    NhanVien* data;
    Node* next;
};

struct ListNV{
    Node* head;
};

// cau 1
float RandomHeSo(float min, float max){
    int lMin = min / 0.1;
    int lMax = max / 0.1;

    float res = lMin + rand() % (lMax - lMin + 1);
    res *= 1.0;

    return res;
}

// cau 2
void ChuanHoaChuoi(char* &str){
    if (str == NULL) return;

    char line[1000];
    char res[1000] = "";
    strcpy(line, str);

    char* token = strtok(line, " ");
    while (token != NULL){
        int lentoken = strlen(token);
        for (int i = 0; i < lentoken; i++){
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
NhanVien* CreateNhanVien(const char* inputStr){
    NhanVien* nv = new NhanVien;
    nv->hoTen = new char[1000];
    nv->maNV = new char[1000];
    nv->phongBan = new char[1000];
    
    char line[1000];
    strcpy(line, inputStr);

    char* id = strtok(line, ";");
    char* name = strtok(NULL, ";");
    char* phongban = strtok(NULL, ";");
    char* luongS = strtok(NULL, ";");

    if (id && name && phongban && luongS){
        int luong = atoi(luongS);

        strcpy(nv->hoTen, name);
        strcpy(nv->maNV, id);
        strcpy(nv->phongBan, phongban);

        ChuanHoaChuoi(nv->phongBan);
        ChuanHoaChuoi(nv->hoTen);

        nv->luongCoBan = luong;
        nv->heSoHieuQua = RandomHeSo(0.0, 5.0);
    }

    return nv;
}

// cau 4
char* NhanVienToString(const NhanVien* pNV){
    char* line = new char[1000];

    sprintf(line, "[%s] %s - %s (Luong: %d | HS: %.1f)", pNV->maNV, pNV->hoTen, pNV->phongBan, pNV->luongCoBan, pNV->heSoHieuQua);

    return line;
}

// ham khoi tao Node
Node* createNode(NhanVien* nv){
    Node* newNode = new Node;
    newNode->data = nv;
    newNode->next = NULL;
    
    return newNode;
}

// ham khoi tao List
ListNV createList(){
    ListNV list;
    list.head = NULL;
    
    return list;
}

// cau 5
void LoadData(const char* filename, ListNV &list){
    ifstream fin;

    fin.open(filename);

    if (fin.is_open() == false){
        cout << "Khong the mo file" << endl;
        return;
    }

    Node* tmp = list.head;

    char line[1000];
    while (fin.getline(line, 1000)){
        NhanVien* newNV = CreateNhanVien(line);
        Node* newNode = createNode(newNV);

        if (list.head == NULL){
            list.head = newNode;
            tmp = list.head;
        }
        else{
            tmp->next = newNode;
            tmp = tmp->next;
        }
    }

    fin.close();
}

// cau 6
void FreeList(ListNV &list){
    if (list.head == NULL) return;
    
    Node* tmp = list.head;
    while (tmp != NULL){
        delete []tmp->data->hoTen;
        delete []tmp->data->maNV;
        delete []tmp->data->phongBan;
        delete tmp->data;
        Node* del = tmp;
        tmp = tmp->next;

        delete del;
    }
}

// ham Print List
void PrintList(ListNV list){
    if (list.head == NULL) return;

    Node* tmp = list.head;
    while (tmp != NULL){
        char* xuat = NhanVienToString(tmp->data);
        cout << xuat << endl;
        delete []xuat;

        tmp = tmp->next;
    }
}

// comp luong co ban (giam dan). 1 la can swap
int comparebyluongcoban(NhanVien* a, NhanVien* b){
    if (a->luongCoBan < b->luongCoBan){
        return 1;
    }
    else if (a->luongCoBan == b->luongCoBan){
        return 0;
    }
    else{
        return -1;
    }
}

// comp ten phong ban (tang dan). true la can swap
bool comparebytenphongban(NhanVien* a, NhanVien* b){
    if (strcmp(a->phongBan, b->phongBan) > 0){
        return true;
    }
    else{
        return false;
    }
}

// ham sap xep
void sortListNV(ListNV &list, int(*compLuong)(NhanVien* a, NhanVien* b), bool(*compPhongBan)(NhanVien* a, NhanVien* b)){
    for (Node* i = list.head; i != NULL; i = i->next){
        Node* truoc = i;
        for (Node* j = i->next; j != NULL; j = j->next){
            if (compLuong(truoc->data, j->data) == 1){
                truoc = j;
            }
            else if (compLuong(truoc->data, j->data) == 0){
                if (compPhongBan(truoc->data, j->data) == true){
                    truoc = j;
                }
            }
        }

        NhanVien* tmp = truoc->data;
        truoc->data = i->data;
        i->data = tmp;
    }
}

// cau 7
void PrintSortedList(ListNV list){
    if (list.head == NULL) return;

    sortListNV(list, comparebyluongcoban, comparebytenphongban);
    PrintList(list);
}

// cau 8

void deepCopy(NhanVien* des, NhanVien* src){
    des->hoTen = new char[1000];
    des->maNV = new char[1000];
    des->phongBan = new char[1000];

    strcpy(des->hoTen, src->hoTen);
    strcpy(des->maNV, src->maNV);
    strcpy(des->phongBan, src->phongBan);
    des->heSoHieuQua = src->heSoHieuQua;
    des->luongCoBan = src->luongCoBan;

}

void CopyLoc(ListNV list, ListNV &listLoc){
    if (list.head == NULL) return;

    Node* tmp = list.head;
    Node* tail = listLoc.head;

    while (tmp != NULL){
        bool ok = true;

        if (tmp->data->heSoHieuQua < 3.5 || strcmp(tmp->data->phongBan, "IT") != 0){
            ok = false;
        }

        if (ok == true){
            NhanVien* newNV = new NhanVien;
            deepCopy(newNV, tmp->data);
            
            Node* newNode = createNode(newNV);

            if (listLoc.head == NULL){
                listLoc.head = newNode;
                tail = listLoc.head;
            }
            else{
                tail->next = newNode;
                tail = tail->next;
            }
        }

        tmp = tmp->next;
    }
}


int main(){
    srand(time(NULL));

    ListNV list = createList();
    LoadData("nhanvien.txt", list);
    
    cout << "--- DANH SACH NHAN VIEN ---" << endl;
    PrintSortedList(list);

    ListNV listLoc = createList();
    CopyLoc(list, listLoc);
    PrintList(listLoc);

    FreeList(list);
    FreeList(listLoc);
    return 0;
}