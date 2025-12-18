#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

char* compressString(char* src){
    char* s = new char [1000];
    int len = strlen(src);

    if (len == 0){
        strcpy(s, "");
        return s;
    }
    else if (len == 1){
        strcpy(s, src);
        strcat(s, "1");
        return s;
    }

    strcpy(s, "");

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
        sprintf(tmp, "%c1", src[len - 1]);

        strcat(s, tmp);
    }

    return s;
}