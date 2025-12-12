#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node{
    int data;
    Node* next;
};

struct List{
    Node* head;
};

Node* CreateNode(const int &value){
    Node *p = new Node;
    if (p != NULL){
        p->data = value;
        p->next = NULL;
    }

    return p;
}

List* CreateLinkedList(){
    List* list = new List;
    if (list != NULL){
        list->head = NULL;
    }

    return list;
}

bool AddNode(List *list, const int &value){
    Node* p = CreateNode(value);
    if (p == NULL){
        return false;
    }

    if (list->head == NULL){
        list->head = p;
        return true;
    }

    Node* tmp = list->head;
    while (tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = p;
    return true;
}

bool InsertNode(List* list, Node* node, const int &value){
    Node* p = CreateNode(value);
    if (p == NULL){
        return false;
    }

    Node* tmp = NULL;
    for (tmp = list->head; tmp != NULL; tmp = tmp->next){

        if (tmp == node){
            break;
        }
    }

    if (tmp == NULL){
        // ko tim thay
        return false;
    }

    p->next = node->next;
    node->next = p;

    return true;
}

int DeleteNode(List* list, const int &value){
    int sl = 0;

    while (list->head != NULL && list->head->data == value){
        Node* del = list->head;
        list->head = list->head->next;
        delete del;
        sl++;
    }

    
    if (list->head == NULL) return sl;

    Node* tmp = list->head;
    while (tmp->next != NULL){
        if (tmp->next->data == value){
            Node* del = tmp->next;
            tmp->next = del->next;
            delete del;
            sl++;
        }
        else{
            tmp = tmp->next; 
        }
    }

    return sl;
}

void DeleteLinkedList(List* list){
    Node* p = list->head;
    while (p != NULL){
        list->head = p->next;

        delete p;
        p = list->head;
    }
    
    delete list;
}

List* GenerateLinkedList(const int &slMin, const int &slMax, const int &gtMin, const int &gtMax){
    List* list = CreateLinkedList();

    if (list == NULL){
        return NULL;
    }

    int sl = slMin + rand() % (slMax - slMin + 1);
    for (int i = 0; i < sl; i++){
        AddNode(list, gtMin + rand() % (gtMax - gtMin + 1));
    }
    
    return list;
}

bool compTangDanValue(Node* a, Node* b){
    if (a->data > b->data){
        return true;
    }
    else{
        return false;
    }
}

void sapxepList(List* list, bool(*compare)(Node* a, Node* b)){
    for (Node* i = list->head; i != NULL; i = i->next){
        Node* min = i;

        for (Node* j = i->next; j != NULL; j = j->next){
            if (compare(min, j) == true){
                min = j;
            }
        }

        int tmp = min->data;
        min->data = i->data;
        i->data = tmp;
    }
}

void printList(List* list){
    if (list->head == NULL){
        cout << "Danh sanh rong" << endl;
        return;
    }

    Node* tmp = list->head;
    cout << "Danh sach: ";
    while (tmp != NULL){
        cout << tmp->data << " ";
        
        tmp = tmp->next;
    }
    cout << endl;
}

List* findListLargerThanX(List* list, int x){
    if (list->head == NULL){
        return NULL;
    }
    
    Node* prev = NULL;
    Node* tmp = list->head;
    while (tmp != NULL){
        if (tmp->data >= x){
            break;
        }

        prev = tmp;
        tmp = tmp->next;
    }
    if (prev == NULL){
        list->head = NULL;
    }
    else{
        prev->next = NULL;
    }
    List* newList = CreateLinkedList();
    newList->head = tmp;

    return newList;
}

int main(){
    srand(time(NULL));
    List* list = GenerateLinkedList(10, 100, -50, 50);
    printList(list);

    sapxepList(list, compTangDanValue);

    int x = -10 + rand() % (10 + 10 + 1);
    cout << "Gia tri cua x la: " << x << endl;

    List* largerList = findListLargerThanX(list, x);
    cout << "List be hon x: " << endl;
    printList(list);
    cout << "List lon hon bang x: " << endl;
    printList(largerList);
    
    DeleteLinkedList(list);
    DeleteLinkedList(largerList);
    return 0;
}