#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;

    bool ok = false;

    int dem[256] = {0};
    for (int i = 0; i < (int)s.size(); i++){
        dem[(int)s[i]]++;
        if (dem[(int)s[i]] > 1){
            ok = true;
            cout << s[i];
            break;
        }
    }

    if (ok == false){
        cout << "NONE";
    }

    return 0;
}