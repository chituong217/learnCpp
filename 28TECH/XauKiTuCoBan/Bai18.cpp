#include <iostream>
#include <string.h>

#define MAX_LEN 10001

using namespace std;

char a[5005][1000];

void swap(char a[], char b[]){
    char tmp[1000];
    strcpy(tmp, a);
    strcpy(a, b);
    strcpy(b, tmp);
}

void bubleSort(char a[][1000], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - i -1; j++){
            int len1 = strlen(a[j]);
            int len2 = strlen(a[j+1]);
            if (len1 > len2){
                swap(a[j], a[j+1]);
            }
            else if (len1 == len2){
                if (strcmp(a[j], a[j+1]) > 0){
                    swap(a[j], a[j+1]);
                }
            }
        }
    }
}

int main(){
    
    int idx = 0;
    char s[MAX_LEN];
    cin.getline(s, MAX_LEN);
    char *token = strtok(s, " ");
    while (token != NULL){
        strcpy(a[idx], token);
        idx++;
        token = strtok(NULL, " ");
    }
    bubleSort(a, idx);
    for (int i = 0; i < idx; i++){
        cout << a[i] << ' ';
    }

    return 0;
}