#include <iostream>
#include <string.h>
#define MAX_LEN 10001

using namespace std;

bool is28Tech(char s[]){
    for (int i = 0; i < (int)strlen(s); i++){
        s[i] = tolower(s[i]);
    }
    if (strcmp(s, "28tech") == 0){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    char s[MAX_LEN];
    cin.getline(s, MAX_LEN);
    int cnt = 0;
    char *token = strtok(s, " ");
    while (token != NULL){
        if (is28Tech(token)){
            cnt++;
        }
        token = strtok(NULL, " ");
    }
    cout << cnt << endl;
    return 0;
}