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

List* merge2ListTangDan(List* list1, List* list2){
    List* list = CreateLinkedList();
    if (list == NULL) return NULL;

    Node* p1 = list1->head;
    Node* p2 = list2->head;

    Node* tail = NULL;

    while (p1 != NULL && p2 != NULL){
        int val;
        if (p1->data < p2->data){
            val = p1->data;

            p1 = p1->next;
        }
        else{
            val = p2->data;

            p2 = p2->next;
        }

        Node* newNode = CreateNode(val);
        if (list->head == NULL){
            list->head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = tail->next;
        }
    }

    while (p1 != NULL){
        int val = p1->data;

        Node* newNode = CreateNode(val);
        if (list->head == NULL){
            list->head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = tail->next;
        }

        p1 = p1->next;
    }

    while (p2 != NULL){
        int val = p2->data;
        
        Node* newNode = CreateNode(val);
        if (list->head == NULL){
            list->head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = tail->next;
        }

        p2 = p2->next;
    }

    return list;
}

int main(){
    srand(time(NULL));
    List* list1 = GenerateLinkedList(5, 100, -1000, 2000);
    printList(list1);
    List* list2 = GenerateLinkedList(5, 100, -1000, 2000);
    printList(list2);

    // sapxep2ds
    sapxepList(list1, compTangDanValue);
    sapxepList(list2, compTangDanValue);

    List* mergedList = merge2ListTangDan(list1, list2);
    cout << "Danh sach da duoc gop : \n";
    printList(mergedList);

    DeleteLinkedList(list1);
    DeleteLinkedList(list2);
    DeleteLinkedList(mergedList);
    return 0;
}