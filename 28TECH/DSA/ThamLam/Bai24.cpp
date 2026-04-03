#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;
    // 1 la Ti, 2 la Teo

    int dem[256] = {0};
    for (int i = 0; i < (int)s.size(); i++){
        dem[(int)s[i]]++;
    }

    int cntLe = 0, cntChan = 0;
    for (int i = 0; i < 256; i++){
        if (dem[i] > 0){
            if (dem[i] % 2 == 0){
                cntChan++;
            }
            else{
                cntLe++;
            }
        }
    }

    if (cntLe % 2 == 1){
        cout << "1";
    }
    else{
        cout << "2";
    }

    return 0;
}