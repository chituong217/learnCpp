#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;

    bool ok = true;

    for (int i = 1; i < (int)s.size(); i++){
        if (abs(s[i] - s[i - 1]) != 1){
            ok = false;
            break;
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