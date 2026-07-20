#include <iostream>
#include <string.h>
#include <ctype.h>
#define MAX_LEN 10001

using namespace std;

int main(){
    char s[MAX_LEN];
    cin.getline(s, MAX_LEN);
    char number[MAX_LEN];
    int idxnum = 0;
    char alpha[MAX_LEN];
    int idxalpha = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++){
        if (isdigit(s[i])){
            number[idxnum] = s[i];
            idxnum++;
        }
        else if (isalpha(s[i])){
            alpha[idxalpha] = s[i];
            idxalpha++;
        }
    }
    number[idxnum] = '\0';
    alpha[idxalpha] = '\0';
    cout << number << endl;
    cout << alpha << endl;
    return 0;
}