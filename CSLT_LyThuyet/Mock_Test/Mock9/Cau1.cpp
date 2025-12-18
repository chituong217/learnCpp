#include <iostream>
#include <cstring>
#include <cstdlin>

using namespace std;

char* compressString(char* src){
    char* s = new char [1000];
    int len = strlen(src);
    strcpy(len, "");

    for (int i = 0; i < len - 1; i++){
        int cnt = 1;
        while (src[i] == src[i + 1] && i < len){
            // neu ki tu htai = kitu tiep theo
            cnt++;
            i++;
        }

        char tmp[100];
        sprintf(tmp, "%c%d", src[i], cnt);

        strcat(s, tmp);
    }

    if (src[len - 2] != src[len - 1]){
        char tmp[100];
        sprintf(tmp, "%c1", src[i]);

        strcat(s, tmp);
    }

    return s;
}