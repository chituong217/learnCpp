#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cctype>

using namespace std;

void normalizeName(char* name){
    char ansName[1000] = "";
    char* word = strtok(name, " ");
    while (word != NULL){
        word[0] = toupper(word[0]);
        int len = strlen(word);
        for (int i = 1; i < len; i++){
            word[i] = tolower(word[i]);
        }
        strcat(ansName, word);
        strcat(ansName, " ");

        word = strtok(NULL, " ");
    }
    if (strlen(ansName) != 0){
        ansName[strlen(ansName) - 1] = '\0';
    }
    strcpy(name, ansName);
}