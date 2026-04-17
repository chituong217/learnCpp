#include <iostream>
#include <string>

using namespace std;

struct vdv{
    string maso, ten, monthidau;
    int namsinh;
    double chieucao, cannang;
};

struct Node{
    vdv data;
    Node* next;
};

struct List{
    Node* head;
};

Node* createNode(vdv data){
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// ham de dem so luong vdv co mon thi dau la bong da
int demVDVCoMonThiDauLaBongDa(List list){
    string aim = "bong da";

    int cnt = 0;
    Node* tmp = list.head;
    while (tmp != NULL){
        if (tmp->data.monthidau == aim){
            cnt++;
        }

        tmp = tmp->next;
    }

    return cnt;
}

void printNode(Node* head){
    cout << "Ma so : " << head->data.maso << endl;
    cout << "Ten : " << head->data.ten << endl;
    cout << "Mon thi dau : " << head->data.monthidau << endl;
    cout << "Nam sinh :  " << head->data.namsinh << endl;
    cout << "Chieu cao : " << head->data.chieucao << endl;
    cout << "Can nang : " << head->data.cannang << endl;
}

// in ra ten cua nhung vdv tren 15 tuoi va cao 1,65m
void printVDVTheoYeuCau(List list){
    int aimAge = 15, currentYear = 2026;
    double aimHeight = 1.65;

    Node* tmp = list.head;
    while (tmp != NULL){
        if ((currentYear - tmp->data.namsinh) > aimAge && tmp->data.chieucao == aimHeight){
            printNode(tmp);
        }

        tmp = tmp->next;
    }
}

int main(){
    return 0;
}