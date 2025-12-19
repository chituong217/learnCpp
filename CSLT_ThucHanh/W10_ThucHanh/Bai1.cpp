#include <iostream>

using namespace std;

struct Data{
    int x;
};

struct Node{
    Data info;
    Node* pNext;
};

struct List{
    Node* pHead;
    Node* pTail;
};

struct Stack{
    List l;
};

// Cau 1
int CompareData(Data info1, Data info2){
    if (info1.x < info2.x){
        return -1;
    }
    else if (info1.x == info2.x){
        return 0;
    }
    else{
        return 1;
    }
}

// Cau 2
void InitList(List &l){
    l.pHead = NULL;
    l.pTail = NULL;
}

// Cau 3
bool isEmptyList(List l){
    if (l.pHead == NULL){
        return true;
    }
    return false;
}

// Cau 4
void PrintList(List l){
    if (l.pHead == NULL) return;

    Node* tmp = l.pHead;
    while (tmp != NULL){
        cout << tmp->info.x << ' ';
        tmp = tmp->pNext;
    }
}

// Cau 5
Node* CreateNode(Data info){
    Node* newNode = new Node;
    if (newNode == NULL){
        return NULL;
    }

    newNode->info = info;
    newNode->pNext = NULL;

    return newNode;
}

// Cau 6
Node* GetNodePointer(List l, Data info){
    if (l.pHead == NULL){
        return NULL;
    }

    Node* tmp = l.pHead;
    while(tmp != NULL){
        if (tmp->info.x == info.x){
            return tmp;
        }
        tmp = tmp->pNext;
    }

    return NULL;
}

// Cau 7
Node* GetNodePointer(List l, int index){
    if (l.pHead == NULL || index < 0){
        return NULL;
    }

    int listIndex = 0;
    Node* tmp = l.pHead;
    
    while (tmp != NULL){
        if (listIndex == index){
            return tmp;
        }

        tmp = tmp->pNext;
        listIndex++;
    }

    return NULL;
}

// Cau 8
int GetNodeIndex(List l, Node* pNode){
    if (l.pHead == NULL){
        return -1;
    }

    int index = 0;
    Node* tmp = l.pHead;

    while (tmp != NULL){
        if (tmp == pNode){
            return index;
        }
        tmp = tmp->pNext;
        index++;
    }

    return -1;
}

// Cau 9
Node* GetPreviousNodePointer(List l, Node* pNode){
    if (l.pHead == NULL){
        return NULL;
    }

    Node* current = l.pHead;
    Node* prev = NULL;
    while (current != NULL){
        if (current == pNode){
            return prev;
        }
        prev = current;
        current = current->pNext;
    }

    return NULL;
}

// Cau 10
void AddHead(List &l, Node* pNewNode){
    if (l.pHead == NULL){
        l.pHead = pNewNode;
        l.pTail = l.pHead;
        return;
    }

    pNewNode->pNext = l.pHead;
    l.pHead = pNewNode;
}


// cau 11
Node* AddHead(List &l, Data info){
    Node* newNode = CreateNode(info);
    if (newNode == NULL){
        return NULL;
    }

    if (l.pHead == NULL){
        l.pHead = newNode;
        l.pTail = l.pHead;
        return newNode;
    }

    newNode->pNext = l.pHead;
    l.pHead = newNode;

    return newNode;
}

// cau 12
void AddTail(List &l, Node *pNewNode){
    if (l.pHead == NULL){
        l.pHead = pNewNode;
        l.pTail = pNewNode;
        return;
    }

    l.pTail->pNext = pNewNode;
    l.pTail = pNewNode;
}

// cau 13
Node* AddTail(List &l, Data info){
    Node* pNewNode = CreateNode(info);
    if (pNewNode == NULL){
        return NULL;
    }

    if (l.pHead == NULL){
        l.pHead = pNewNode;
        l.pTail = pNewNode;
        return pNewNode;
    }

    l.pTail->pNext = pNewNode;
    l.pTail = pNewNode;

    return pNewNode;
}

// cau 14
void AddAfter(List &l, Node *q, Node* pNewNode){
    if (q == NULL) {
        return;
    }
    
    if (pNewNode == NULL) {
        return;
    }

    pNewNode->pNext = q->pNext;
    q->pNext = pNewNode;

    if (l.pTail == q) {
        l.pTail = pNewNode;
    }
}

// cau 15
Node* AddAfter(List &l, Node *q, Data info){
    if (q == NULL){
        return NULL;
    }    

    Node* pNewNode = CreateNode(info);
    if (pNewNode == NULL){
        return NULL;
    }

    pNewNode->pNext = q->pNext;
    q->pNext = pNewNode;

    if (l.pTail == q) {
        l.pTail = pNewNode;
    }

    return pNewNode;
}

// cau 16
void AddBefore(List &l, Node* q, Node* pNewNode){
    if (q == NULL || pNewNode == NULL){
        return;
    }

    if (q == l.pHead){
        pNewNode->pNext = q;
        l.pHead = pNewNode;
        return;
    } 

    Node* current = l.pHead;
    while (current != NULL){
        if (current->pNext == q){
            break;
        }

        current = current->pNext;
    }

    pNewNode->pNext = q;
    current->pNext = pNewNode;
}

// cau 17
Node* AddBefore(List &l, Node *q, Data info){
    Node* pNewNode = CreateNode(info);

    if (q == NULL || pNewNode == NULL){
        return NULL;
    }

    if (q == l.pHead){
        pNewNode->pNext = q;
        l.pHead = pNewNode;
        return pNewNode;
    } 

    Node* current = l.pHead;
    while (current != NULL){
        if (current->pNext == q){
            break;
        }

        current = current->pNext;
    }

    pNewNode->pNext = q;
    current->pNext = pNewNode;

    return pNewNode;
}

// cau 18
void AddAscendingList(List &l, Node* pNewNode){
    if (pNewNode == NULL){
        return;
    }

    if (l.pHead == NULL || l.pHead->info.x > pNewNode->info.x){
        AddHead(l, pNewNode);
        return;
    }

    Node* current = l.pHead;
    while (current != NULL){
        if (current->info.x <= pNewNode->info.x){
            if (current->pNext == NULL){
                current->pNext = pNewNode;
                l.pTail = pNewNode;
                return;
            }
            if (current->pNext->info.x > pNewNode->info.x){
                pNewNode->pNext = current->pNext;
                current->pNext = pNewNode;
                return;
            }
        }

        current = current->pNext;
    }
}

// cau 19
Node* AddAscendingList(List &l, Data info){
    Node* pNewNode = CreateNode(info);
    
    if (pNewNode == NULL){
        return NULL;
    }

    if (l.pHead == NULL || l.pHead->info.x > pNewNode->info.x){
        AddHead(l, pNewNode);
        return pNewNode;
    }

    Node* current = l.pHead;
    while (current != NULL){
        if (current->info.x <= pNewNode->info.x){
            if (current->pNext == NULL){
                current->pNext = pNewNode;
                l.pTail = pNewNode;
                return pNewNode;
            }
            if (current->pNext->info.x > pNewNode->info.x){
                pNewNode->pNext = current->pNext;
                current->pNext = pNewNode;
                return pNewNode;
            }
        }

        current = current->pNext;
    }

    return NULL;
}

// cau 20
Data RemoveHead(List &l){
    Data tmp = l.pHead->info;

    if (l.pHead->pNext == NULL){
        delete l.pHead;
        l.pHead = NULL;
        l.pTail = NULL;
    }
    else{
        Node* del = l.pHead;
        l.pHead = l.pHead->pNext;
        delete del;
    }

    return tmp;
}

// cau 21
Data RemoveTail(List &l){
    Data tmp = l.pTail->info;

    if (l.pHead == l.pTail){
        delete l.pHead;
        l.pHead = l.pTail = NULL;
    }
    else{
        Node* beforeTail = l.pHead;
        while (beforeTail->pNext != l.pTail){
            beforeTail = beforeTail->pNext;
        }
        beforeTail->pNext = NULL;
        delete l.pTail;

        l.pTail = beforeTail;
    }

    return tmp;
}

// cau 22
Data RemoveAfter(List &l, Node *q){
    if (q->pNext == l.pTail){
        l.pTail = q;
    }

    Node* del = q->pNext;
    Data tmp = del->info;

    q->pNext = del->pNext;
    delete del;

    return tmp;
}

// cau 23
bool RemoveNode(List &l, Data info){
    if (l.pHead == NULL){
        return false;
    }
    else if (l.pHead->info.x == info.x){
        Node* del = l.pHead;
        l.pHead = l.pHead->pNext;

        if (l.pHead == NULL){
            l.pTail = NULL;
        }

        delete del;
        return true;
    }

    bool found = false;
    Node* prev = NULL;
    Node* current = l.pHead;
    while (current != NULL){
        if (current->info.x == info.x){
            found = true;
            break;
        }

        prev = current;
        current = current->pNext;
    }

    if (found == true){
        if (current == l.pTail){
            l.pTail = prev;
        }

        prev->pNext = current->pNext;
        delete current;
    }

    return found;
}

// cau 24
void RemoveList(List &l){
    if (l.pHead == NULL){
        return;
    }

    Node* tmp = l.pHead;
    while (tmp != NULL){
        Node* del = tmp;

        tmp = tmp->pNext;
        delete del;
    }

    l.pHead = l.pTail = NULL;
}

// Cau 25
int RemoveKeys(List &l, Data k){
    if (l.pHead == NULL){
        return 0;
    }
    int cnt = 0;

    while (RemoveNode(l, k) == true){
        cnt++;
    }

    return cnt;
}

// cau 29
void HoanViNode(List &l, Node *p, Node *q) {
    Node *pPrevious = GetPreviousNodePointer(l, p);
    Node *pNextOfP = p->pNext;
    Node *qPrevious = GetPreviousNodePointer(l, q);
    Node *qNextOfQ = q->pNext;

    if (pPrevious != NULL) {
        pPrevious->pNext = q;
    }
    else {
        l.pHead = q;
    }

    if (pNextOfP == q) {
        q->pNext = p;
    }
    else {
        q->pNext = pNextOfP;
        qPrevious->pNext = p;
    }

    p->pNext = qNextOfQ;

    if (qNextOfQ == NULL) {
        l.pTail = p;
    }
}

// cau 26
void SortList(List &l) {
    if (l.pHead == NULL || l.pHead->pNext == NULL) {
        return;
    }

    for (Node* p = l.pHead; p->pNext != NULL; p = p->pNext) {
        for (Node* q = p->pNext; q != NULL; q = q->pNext) {
            if (p->info.x > q->info.x) {
                HoanViNode(l, p, q);
                
                Node* temp = p;
                p = q;
                q = temp;
            }
        }
    }
}

// cau 27
List CombineList(const List &l1, const List &l2) {
    List l;
    InitList(l);

    if (l1.pHead == NULL && l2.pHead == NULL) {
        return l;
    }

    Node* currentL1 = l1.pHead;
    while (currentL1 != NULL) {
        AddAscendingList(l, currentL1->info);
        currentL1 = currentL1->pNext;
    }

    Node* currentL2 = l2.pHead;
    while (currentL2 != NULL) {
        AddAscendingList(l, currentL2->info);
        currentL2 = currentL2->pNext;
    }

    return l;
}

// cau 28
void ReverseList (List &l){
    if (l.pHead == NULL){
        return;
    }

    Node* prev = NULL;
    Node* current = l.pHead;
    Node* next = NULL;

    while (current != NULL){
        next = current->pNext;
        current->pNext = prev;

        prev = current;
        current = next;
    }

    Node* tmp = l.pHead;
    l.pHead = l.pTail;
    l.pTail = tmp;
}

// stack
void InitStack(Stack &s){
    InitList(s.l);
}

bool Stack_IsEmpty(const Stack &s){
    return isEmptyList(s.l);
}

Data Stack_Pop(Stack &s){
    Data info;
    if(!Stack_IsEmpty(s)){
        info = RemoveHead(s.l);
    }
    return info;
}


bool Stack_Push(Stack &s, const Data &info){
    Node *p = CreateNode(info);
    if(p==NULL)
        return false;
    AddHead(s.l, p);
    return true;
}


void Stack_Clear(Stack &s){
    RemoveList(s.l);
}