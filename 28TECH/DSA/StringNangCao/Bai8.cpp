#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;

    int dem[256] = {0};
    for (int i = 0; i < (int)s.size(); i++){
        char kitu = tolower(s[i]);
        dem[kitu]++;
    }

    bool ok = true;
    for (int i = (int)'a'; i <= (int)'z'; i++){
        if (dem[i] == 0){
            ok = false;
        }
    }

    if (ok == true){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}