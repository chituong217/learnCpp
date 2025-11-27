#include <iostream>
#include <string.h>

using namespace std;

int main(){
    string s;
    getline(cin, s);
    int dem[256] = {0};
    int len = s.size();
    bool isFound = false;
    for (int i = 0; i < len; i++){
        dem[(int)s[i]]++;
        if (dem[(int)s[i]] == 2){
            isFound = true;
            cout << s[i] << endl;
            break;
        }
    }
    if (isFound == false){
        cout << "NONE" << endl;
    }
    return 0;
}