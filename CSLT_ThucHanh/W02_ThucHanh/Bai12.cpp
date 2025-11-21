#include <iostream>
using namespace std;

int comp(const void *a, const void *b){
    int *x = (int *)a;
    int *y = (int *)b;
    return *x - *y;
}

int main(){
    int mang[4];
    for (int i=0; i<4; i++){
        cin >> mang[i];
    }
    qsort(mang, 4, sizeof(int), comp);
    for (int i=0; i<4; i++){
        cout << mang[i] << " ";
    }
    return 0;
}