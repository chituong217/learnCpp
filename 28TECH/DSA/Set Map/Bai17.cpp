#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;

    int dem[256] = {0};

    for (int i = 0; i < (int)s.size(); i++){
        dem[ (int)s[i] ]++;
    }

    int min = INT_MAX, max = INT_MIN, cnt = 0;
    for (int i = 0; i < 256; i++){
        if (dem[i] > 0){
            cnt++;
            if (dem[i] > max){
                max = dem[i];
            }
            if (dem[i] < min){
                min = dem[i];
            }
        }
    }

    for (int i = 0; i < 256; i++){
        if (dem[i] == max){
            cout << (char)i << ' ' << dem[i] << endl;
            break;
        }
    }

    for (int i = 255; i >= 0; i--){
        if (dem[i] == min){
            cout << (char)i << ' ' << dem[i] << endl;
            break;
        }
    }

    cout << cnt << endl;

    return 0;
}