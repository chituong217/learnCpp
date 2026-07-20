#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

struct GiaoDich{
    char* maGD;
    char* ngayGD;
    char* noiDung;
    long long soTien;
};

struct Node{
    GiaoDich* data;
    Node* pNext;
};

struct SaoKe{
    Node* pHead;
    Node* pTail;
};

// cau 1
bool IsValidDate(const char* dateStr){
    if (dateStr == NULL){
        return NULL;
    }

    char line[100];
    strcpy(line, dateStr);

    char* dayS = strtok(line, "/");
    char* monthS = strtok(NULL, "/");
    char* yearS = strtok(NULL, "/");

    if (dayS == NULL || monthS == NULL || yearS == NULL){
        return false;
    }

    int day = atoi(dayS);
    int month = atoi(monthS);
    int year = atoi(yearS);

    bool isNamNhuan = false;
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
        isNamNhuan = true;
    }

    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        return day <= 31;
    }
    else if (month == 2){
        if (isNamNhuan == true){
            return day <= 29;
        }
        else{
            return day <= 28;
        }
    }
    else{
        return day <= 30;
    }
}

// cau 2
void MaskInfo (char* &noiDung){
    if (noiDung == NULL){
        return;
    }

    int len = strlen(noiDung);
    for (int i = 0; i < len; i++){
        if (isdigit(noiDung[i]) == true){
            noiDung[i] = '*';
        }
    }
}

// Ham generate magd
char* generateMaGiaoDich(){
    char* id = new char[10];
    char res[10] = "TRX";

    int min = 0;
    int max = 9;

    for (int i = 0; i < 5; i++){
        int so = min + rand() % (max - min + 1);
        int len = strlen(res);
        sprintf(res + len, "%d", so);
    }
    
    strcpy(id, res);

    return id;
}

// cau 3
GiaoDich* CreateGiaoDich(const char* inputStr){
    if (inputStr == NULL){
        return NULL;
    }

    char line[1000];
    strcpy(line, inputStr);

    char* ngay = strtok(line, ";");
    char* noidung = strtok(NULL, ";");
    char* sotien = strtok(NULL, ";");

    if (ngay && noidung && sotien && IsValidDate(ngay)){
        GiaoDich* newGD = new GiaoDich;
        
        newGD->maGD = generateMaGiaoDich();
        
        newGD->ngayGD = new char[100];
        strcpy(newGD->ngayGD, ngay);

        newGD->noiDung = new char[1000];
        strcpy(newGD->noiDung, noidung);

        newGD->soTien = atoll(sotien);

        return newGD;
    }

    return NULL;
}

// cau 4
char* GiaoDichToString(const GiaoDich* pGD){
    if (pGD == NULL){
        return NULL;
    }

    char* line = new char[1000];
    sprintf(line, "[%s] %s : %lld VND", pGD->ngayGD, pGD->noiDung, pGD->soTien);

    return line;
}

// ham tao node
Node* createNode(GiaoDich* newGD){
    if (newGD == NULL){
        return NULL;
    }

    Node* newNode = new Node;
    newNode->data = newGD;
    newNode->pNext = NULL;
    
    return newNode;
}

// ham khoi tao list
SaoKe createList(){
    SaoKe list;
    list.pHead = list.pTail = NULL;

    return list;
}

// ham add tail
void addTail(SaoKe &list, GiaoDich* gd){
    Node* newNode = createNode(gd);
    
    if (list.pHead == NULL){
        list.pHead = newNode;
        list.pTail = list.pHead;
    }
    else{
        list.pTail->pNext = newNode;
        list.pTail = newNode;
    }
}

// cau 5
void LoadData(const char* filename, SaoKe &list){
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
    while(fin.getline(line, 1000)){
        GiaoDich* newGD = CreateGiaoDich(line);

        if (newGD != NULL){
            addTail(list, newGD);
        }
    }

    fin.close();
}

// cau 6
void FreeList(SaoKe &list){
    if (list.pHead == NULL){
        return;
    }

    Node* tmp = list.pHead;
    while (tmp != NULL){
        delete []tmp->data->maGD;
        delete []tmp->data->ngayGD;
        delete []tmp->data->noiDung;

        delete tmp->data;

        Node* del = tmp;

        tmp = tmp->pNext;
        delete del;
    }

    list.pHead = list.pTail = NULL;
}

// cau 7
long long CalculateBalance(SaoKe list, long long soDuDauKy){
    if (list.pHead == NULL){
        return soDuDauKy;
    }

    long long result = soDuDauKy;
    Node* tmp = list.pHead;
    while (tmp != NULL){
        result += tmp->data->soTien;

        tmp = tmp->pNext;
    }

    return result;
}

// ham printlist
void PrintList(SaoKe list){
    if (list.pHead == NULL){
        return;
    }

    Node* tmp = list.pHead;
    while (tmp != NULL){
        char* del = GiaoDichToString(tmp->data);
        cout << del << endl;
        delete []del;

        tmp = tmp->pNext;
    }
}

// cau 8
void PrintVAR(SaoKe list){
    if (list.pHead == NULL){
        return;
    }

    Node* tmp = list.pHead;
    while (tmp != NULL){
        if (tmp->data->soTien > 50000000 || tmp->data->soTien < -50000000){
            char* noidungmask = new char[1000];
            strcpy(noidungmask, tmp->data->noiDung);
            MaskInfo(noidungmask);

            cout << '[' << tmp->data->ngayGD << ']' << ' ' << noidungmask << " : " << tmp->data->soTien << " VND" << endl;
            delete []noidungmask;
        }

        tmp = tmp->pNext;
    }
}

int main(){
    srand(time(NULL));

    SaoKe list = createList();

    LoadData("saoke.txt", list);

    cout << "--- LICH SU GIAO DICH ---" << endl;
    PrintList(list);

    long long sodudauky;
    cin >> sodudauky;

    cout << CalculateBalance(list, sodudauky) << endl;
    
    cout << "--- DANH SACH GIAO DICH DANG NGHI ---" << endl;
    PrintVAR(list);

    FreeList(list);

    return 0;
}