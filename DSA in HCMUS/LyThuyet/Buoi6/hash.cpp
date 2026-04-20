#include <iostream>
#include <vector>

using namespace std;

const int P = 1e6 + 3;

struct HashTable{
    vector< pair<int, int> > h[P];
};

int getHash(int key){
    return key % P;
}

void insert(HashTable &table, int key, int value){
    int hkey = getHash(key);
    for (auto it = table.h[hkey].begin(); it != table.h[hkey].end(); it++){
        if (it->first == key) return;
    }

    table.h[hkey].push_back({key, value});
}

int find(HashTable table, int key){
    int hkey = getHash(key);
    for (auto it : table.h[hkey]){
        if (it.first == key) return it.second;
    }
    return -1;
}

int main(){

    return 0;
}