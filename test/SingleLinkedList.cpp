#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

typedef Node* node;

node makeNode(int data){
    node newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int size(node head){
    int cnt = 0;
    while (head != NULL){
        cnt++;
        head = head->next;
    }
    return cnt;
}

void display (node head){
    cout << "Cac phan tu trong DSLK: ";
    while (head != NULL){
        cout << head->data << ' ';
        head = head-> next;
    }
    cout << "\n";
}

void push_front(node &head, int data){
    node newNode = makeNode(data);
    newNode->next = head;
    head = newNode;
}

void push_back(node &head, int data){
    node newNode = makeNode(data);
    if (head == NULL){
        head = newNode;
    }
    else{
        node tmp = head;
        while (tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
}

void insert(node &head, int data, int pos){
    int n = size(head);
    if (pos < 1 || pos > n + 1){
        cout << "Vi tri chen khong hop le" << endl;
        return;
    }
    else if (pos == 1){
        push_front(head, data);
    }
    else if (pos == n + 1){
        push_back(head, data);
    }
    else{
        node newNode = makeNode(data);
        node tmp = head;
        for (int i = 1; i < pos - 1; i++){
            tmp = tmp->next;
        }
        newNode->next = tmp->next;
        tmp->next = newNode;
    }
}

void pop_front(node &head){
    if (head == NULL){
        return;
    }
    else{
        node tmp = head;
        head = head->next;
        delete tmp;
    }
    
}

void pop_back(node &head){
    if (head == NULL){
        return;
    }
    else if (head->next == NULL){
        head = head->next;
    }
    else{
        node tmp = head;
        while (tmp->next->next != NULL){
            tmp = tmp->next;
        }
        node last = tmp->next;
        tmp->next = NULL;
        delete last;
    }
    
}

void erase(node &head, int pos){
    int n = size(head);
    if (pos < 1 || pos > n){
        cout << "Vi tri xoa khong hop le" << endl;
        return;
    }
    else{
        if (n == 0){
            return;
        }
        else if (pos == 1){
            pop_front(head);
        }
        else if (pos == n){
            pop_back(head);
        }
        else{
            node tmp = head;
            for (int i = 1; i < pos - 1; i++){
                tmp = tmp->next;
            }
            node middle = tmp->next;
            tmp->next = tmp->next->next;
            delete middle;
        }
    }
}

bool find(node head, int data){
    while (head != NULL){
        if (head->data == data){
            return true;
        }
        head = head->next;
    }
    return false;
}

void sort(node &head){
    for (node i = head; i != NULL; i = i->next){
        node min = i;
        for (node j = i->next; j != NULL; j = j->next){
            if (j->data < min->data){
                min = j;
            }
        }
        int tmp = i->data;
        i->data = min->data;
        min->data = tmp;
    }
}

int main(){
    node head = NULL;
    while(1){
        cout << "---------------------------------------------------\n"; 
        cout << "1. Them 1 node vao dau DSLK\n";
        cout << "2. Them 1 node vao cuoi DSLK\n";
        cout << "3. Chen 1 node vao giua cua DSLK\n";
        cout << "4. Hien thi DSLK\n";
        cout << "5. Xoa 1 node o dau DSLK\n";
        cout << "6. Xoa 1 node o cuoi DSLK\n";
        cout << "7. Xoa 1 node o giua DSLK\n";
        cout << "8. Tim kiem 1 node trong DSLK\n";
        cout << "9. Sap xep DSLK tang dan\n";
        cout << "0. Thoat\n";
        cout << "---------------------------------------------------\n";
        int luachon;
        cin >> luachon;
        if (luachon == 1){
            int data;
            cout << "Nhap vao du lieu: ";
            cin >> data;
            push_front(head, data);
        }
        else if (luachon == 2){
            int data;
            cout << "Nhap vao du lieu: ";
            cin >> data;
            push_back(head, data);
        }
        else if (luachon == 3){
            int pos, data;
            cout << "Nhap vao vi tri chen: ";
            cin >> pos;
            cout << "Nhap vao du lieu: ";
            cin >> data;
            insert(head, data, pos);
        }
        else if (luachon == 4){
            display(head);
        }
        else if (luachon == 5){
            pop_front(head);
        }
        else if (luachon == 6){
            pop_back(head);
        }
        else if (luachon == 7){
            int pos;
            cout << "Nhap vao vi tri xoa: ";
            cin >> pos;
            erase(head, pos);
        }
        else if (luachon == 8){
            cout << "Nhap vao du lieu node can tim: ";
            int data;
            cin >> data;
            if (find(head, data)){
                cout << "Tim thay\n";
            }
            else{
                cout << "Khong tim thay\n";
            }
        }
        else if (luachon == 9){
            sort(head);
        }
        else{
            break;
        }
    }
    return 0;
}