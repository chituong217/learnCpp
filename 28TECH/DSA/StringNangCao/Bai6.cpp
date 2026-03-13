#include <iostream>
#include <string>
#include <sstream>


using namespace std;

int main(){
    string s1, s2;
    cin >> s1 >> s2;

    int dem1[256] = {0}, dem2[256] = {0};
    for (int i = 0; i < (int)s1.size(); i++){
        dem1[s1[i]]++;
    }
    for (int i = 0; i < (int)s2.size(); i++){
        dem2[s2[i]]++;
    }

    for (int i = 0; i < 256; i++){
        if (dem1[i] > 0 && dem2[i] == 0){
            cout << (char)i;
        }
    }

    cout << endl;
    for (int i = 0; i < 256; i++){
        if (dem2[i] > 0 && dem1[i] == 0){
            cout << (char)i;
        }
    }

    return 0;
}