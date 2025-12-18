#include <iostream>

using namespace std;

bool isAnagram(char* s1, char* s2){
    int dem1[256] = {0};
    int dem2[256] = {0};

    int len1 = strlen(s1);
    int len2 = strlen(s2);

    for (int i = 0; i < len1; i++){
        dem1[s1[i]]++;
    }
    for (int i = 0; i < len2; i++){
        dem2[s2[i]]++;
    }

    bool ok = true;
    for (int i = 0; i < 256; i++){
        if (dem1[i] != dem2[i]){
            ok = false;
        }
    }

    return ok;
}