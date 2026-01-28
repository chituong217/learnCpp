#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

void compressString(char* s){
    int len = strlen(s);
    for (int i = 0; i < len; i++){
        int cnt = 1;
        while (i + 1 < len && s[i + 1] == s[i]){
            i++;
            cnt++;
        }
        if (cnt == 1){
            cout << s[i];
        }
        else{
            cout << s[i] << cnt;
        }
    }
}