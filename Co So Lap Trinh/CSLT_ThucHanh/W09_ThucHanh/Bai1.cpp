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

int findMinValue(List* list){
    if (list->head == NULL){
        return 0;
    }
    else if (list->head->next == NULL){
        return list->head->data;
    }

    Node* tmp = list->head;
    int minVal = tmp->data;

    while (tmp != NULL){
        if (tmp->data < minVal){
            minVal = tmp->data;
        }

        tmp = tmp->next;
    }

    return minVal;
}

int findMaxValue(List* list){
    if (list->head == NULL){
        return 0;
    }
    else if (list->head->next == NULL){
        return list->head->data;
    }

    Node* tmp = list->head;
    int maxVal = tmp->data;

    while (tmp != NULL){
        if (tmp->data > maxVal){
            maxVal = tmp->data;
        }

        tmp = tmp->next;
    }

    return maxVal;
}

long long sumListValue(List* list){
    if (list->head == NULL){
        return 0;
    }
    else if (list->head->next == NULL){
        return list->head->data;
    }

    Node* tmp = list->head;
    long long sum = 0;
    while (tmp != NULL){
        sum += tmp->data;

        tmp = tmp->next;
    }
    return sum;
}

int countListMaxValue(List* list){
    if (list->head == NULL){
        return 0;
    }
    else if (list->head->next == NULL){
        return 1;
    }

    Node* tmp = list->head;
    int maxVal = findMaxValue(list);
    int cnt = 0;

    while (tmp != NULL){
        if (tmp->data == maxVal){
            cnt++;
        }

        tmp = tmp->next;
    }

    return cnt;
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

int main(){
    srand(time(NULL));
    List* list = GenerateLinkedList(1, 10, 0, 100);
    printList(list);

    cout << "Gia tri nho nhat: " << findMinValue(list) << endl;
    cout << "Gia tri lon nhat: " << findMaxValue(list) << endl;
    cout << "Tong phan tu: " << sumListValue(list) << endl;
    cout << "So luong phan tu co gia tri lon nhat: " << countListMaxValue(list) << endl;

    DeleteLinkedList(list);
    return 0;
}