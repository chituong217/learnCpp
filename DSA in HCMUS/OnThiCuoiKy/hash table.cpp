#include <bits/stdc++.h>

using namespace std;


struct HashNode {
    int key;
    HashNode* next;
};

struct HashTable {
    HashNode** table; // Mảng động chứa các con trỏ đầu danh sách liên kết
    int m; // Kích thước mảng băm (số lượng bucket)
    int n; // Số lượng phần tử hiện tại
};


void initTable(HashTable &ht, int initSize){
    ht.table = new HashNode*[initSize];

    for (int i = 0; i < initSize; i++){
        ht.table[i] = NULL;
    }

    ht.m = initSize;
    ht.n = 0;
}

HashNode* createNode(int val){
    HashNode* newNode = new HashNode;
    newNode->key = val;
    newNode->next = NULL;

    return newNode;
}

int hashFunction(int key, int m){
    return key % m;
}

void insert(HashTable &ht, int key);

void freeTable(HashTable &ht){
    for (int i = 0; i < ht.m; i++){
        if (ht.table[i] != NULL){
            HashNode* tmp = ht.table[i];
            while (tmp != NULL){
                HashNode* del = tmp;
                tmp = tmp->next;
                delete del;
            }
            ht.table[i] = NULL;
        }
    }

    delete[] ht.table;
}

void rehash(HashTable &ht){
    HashTable htOld;
    initTable(htOld, ht.m);
    for (int i = 0; i < ht.m; i++){
        HashNode* tmp = ht.table[i];
        while (tmp != NULL){
            insert(htOld, tmp->key);
            tmp = tmp->next;
        }
    }

    freeTable(ht);
    initTable(ht, (ht.m*2) + 1);

    for (int i = 0; i < htOld.m; i++){
        HashNode* tmp = htOld.table[i];
        while (tmp != NULL){
            insert(ht, tmp->key);
            tmp = tmp->next;
        }
    }

    freeTable(htOld);
}

void insert(HashTable &ht, int key){ // Có kiểm tra hệ số tải > 0.75 để Rehash
    int hashKey = hashFunction(key, ht.m);

    HashNode* newNode = createNode(key);
    newNode->next = ht.table[hashKey];
    ht.table[hashKey] = newNode;
    ht.n++;

    double loadFactor = 1.0 * ht.n / ht.m;
    if (loadFactor > 0.75){
        rehash(ht);
    }
}

bool search(const HashTable &ht, int key){
    int hashKey = hashFunction(key, ht.m);
    HashNode* tmp = ht.table[hashKey];
    while (tmp != NULL){
        if (tmp->key == key) return true;
        tmp = tmp->next;
    }

    return false;
}

void remove(HashTable &ht, int key){
    int hashKey = hashFunction(key, ht.m);

    if (ht.table[hashKey] == NULL) return;

    if (ht.table[hashKey]->key == key){
        HashNode* del = ht.table[hashKey];
        ht.table[hashKey] = ht.table[hashKey]->next;
        delete del;
        ht.n--;
        return;
    }

    HashNode* prev = NULL;
    HashNode* tmp = ht.table[hashKey];
    while (tmp != NULL){
        if (tmp->key == key){
            prev->next = tmp->next;
            delete tmp;
            ht.n--;
            return;
        }
        prev = tmp;
        tmp = tmp->next;
    }
}
