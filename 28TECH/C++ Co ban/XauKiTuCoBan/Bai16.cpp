#include <iostream>
#include <string.h>
#include <cstdlib>

#define MAX_LEN 1001

using namespace std;

int comp(const void *a, const void *b){
    char *x = (char *)a;
    char *y = (char *)b;
    if (strcmp(x, y) < 0){
        return -1;
    }
    else{
        return 1;
    }
}

int comp2(const void *a, const void *b){
    char *x = (char *)a;
    char *y = (char *)b;
    if (strcmp(x, y) > 0){
        return -1;
    }
    else{
        return 1;
    }
}

int main(){
    char s[MAX_LEN];
    cin.getline(s, MAX_LEN);
    qsort(s, strlen(s), sizeof(char), comp);
    cout << s << endl;
    qsort(s, strlen(s), sizeof(char), comp2);
    cout << s << endl;

    return 0;
}