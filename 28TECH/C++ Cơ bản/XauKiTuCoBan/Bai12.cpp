#include <iostream>
#include <string.h>

#define MAX_LEN 10001

using namespace std;

bool checkInHoa(char s[]){
    int len = strlen(s);
    for (int i = 0; i < len; i++){
        if (islower(s[i])){
            return false;
        }
    }
    return true;
}

int main(){
    char s[MAX_LEN];
    cin.getline(s, MAX_LEN);
    int cnt = 0;
    char *token = strtok(s, " ");
    while (token != NULL){
        if (checkInHoa(token)){
            cnt++;
        }
        token = strtok(NULL, " ");
    }
    cout << cnt << endl;
    return 0;
}