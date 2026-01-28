#include <iostream>
#include <cstring>

using namespace std;

void removeChar(char* str, char target){
    if (str == NULL){
        return;
    }

    int len = strlen(str);
    int idx = 0;
    while (idx < len){
        if (str[idx] == target){
            for (int i = idx; str[i] != '\0'; i++){
                str[i] = str[i + 1];
            }
            len--;
        }
        else{
            idx++;
        }
    }
}
