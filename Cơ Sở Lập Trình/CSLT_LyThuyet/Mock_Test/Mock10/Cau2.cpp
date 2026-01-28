#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

char* normalizeName(char* rawName){
    if (rawName == NULL){
        return NULL;
    }

    char* newName = new char[strlen(rawName)];

    char line[10000];
    char res[10000] = "";
    strcpy(line, rawName);

    char* token = strtok(line, " ");
    while (token != NULL){
        int len = strlen(token);
        for (int i = 0; i < len; i++){
            if (i == 0){
                token[i] = toupper(token[i]);
            }
            else{
                token[i] = tolower(token[i]);
            }
        }

        strcat(res, token);

        token = strtok(NULL, " ");
        if (token != NULL){
            strcat(res, " ");
        }
    }

    strcpy(newName, res);
    return newName;
}