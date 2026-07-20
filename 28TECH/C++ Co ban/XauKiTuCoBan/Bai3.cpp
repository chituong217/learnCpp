#include <iostream>
#include <string>
#include <sstream>
#include <string.h>

using namespace std;

int main(){
    char s[10001];
    cin.getline(s, 10001);
    int len = strlen(s), sum = 0;
    for (int i = 0; i < len; i++){
        if (isdigit(s[i])){
            sum += s[i] - '0';
        }
    }
    cout << sum << endl;
    return 0;
}