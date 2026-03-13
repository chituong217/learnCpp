#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;

    int dem[256] = {0};
    for (int i = 0; i < (int)s.size(); i++){
        dem[s[i]]++;
    }

    for (int i = 0; i < 256; i++){
        if (dem[i] > 0){
            cout << (char)i << ' ' << dem[i] << endl;
        }
    }

    cout << endl;

    for (int i = 0; i < (int)s.size(); i++){
        if (dem[s[i]] > 0){
            cout << s[i] << ' ' << dem[s[i]] << endl;
            dem[s[i]] = 0;
        }
    }

    return 0;
}