#include <iostream>
#include <string.h>

using namespace std;



int main(){
    char c[101], ans[101] = "";
    cin.get(c, 101, '\n');


    const char delim[] = " ";
    char *token = strtok(c, delim);
    while (token != NULL){
        strcat(ans, token);
        token = strtok(NULL, delim);
        if (token != NULL){
            strcat(ans, " ");
        }
    }

    cout << ans;
    return 0;
}