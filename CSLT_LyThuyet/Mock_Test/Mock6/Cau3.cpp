#include <iostream>
#include <cstring>

using namespace std;

void findLongestWord(char* s){
    char a[1000];
    strcpy(a, s);

    int longestLength = 0;
    char* token = strtok(a, " ");
    while(token != NULL){
        int lenTmp = strlen(token);
        if (lenTmp > longestLength){
            longestLength = lenTmp;
        }

        token = strtok(NULL, " ");
    }

    char b[1000];
    strcpy(b, s);
    char* word = strtok(b, " ");
    while (word != NULL){
        if (strlen(word) == longestLength){
            cout << word;
            break;
        }

        word = strtok(NULL, " ");
    }
}