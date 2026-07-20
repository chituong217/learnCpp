#include <iostream>
#include <cstring>

using namespace std;

void sinh(char s[], int len){
    int i = len - 1;
    while(i >= 0 && s[i] == '1'){
        s[i] = '0';
        i--;
    }
    if (i < 0){
        return;
    }
    else{
        s[i] = '1';
    }
}

int main(){
    char s[1001];
    cin.getline(s, 1001);
    int len = strlen(s);
    sinh(s, len);
    for (int i=0; i < len; i++){
        cout << s[i];
    }
    return 0;
}