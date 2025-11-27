#include <iostream>
#include <string.h>

#define MAX_LEN 100

using namespace std;

int main(){
    char s[MAX_LEN];
    cin.getline(s, MAX_LEN);
    int len = strlen(s);
    int cntDaDem = 0;
    char res[MAX_LEN] = "";
    for (int i = len - 1; i >= 0; i--){
        cntDaDem++;
        char tmpString[MAX_LEN];
        tmpString[0] = s[i];
        tmpString[1] = '\0';
        strcat(tmpString, res);
        strcpy(res, tmpString);
        if (cntDaDem == 3 && i != 0){
            char dauphay[MAX_LEN];
            dauphay[0] = ',';
            dauphay[1] = '\0';
            strcat(dauphay, tmpString);
            strcpy(res, dauphay);
            cntDaDem = 0;
        }
    }
    cout << res << endl;
    return 0;
}