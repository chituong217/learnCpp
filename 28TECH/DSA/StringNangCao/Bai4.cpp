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

    int minFre = INT_MAX, maxFre = INT_MIN;

    for (int i = 0; i < 256; i++){
        if (dem[i] > 0 && dem[i] > maxFre){
            maxFre = dem[i];
        }
        if (dem[i] > 0 && dem[i] < minFre){
            minFre = dem[i];
        }
    }

    for (int i = 255; i >= 0; i--){
        if (dem[i] == maxFre){
            cout << (char)i << ' ' << dem[i] << endl;
            break;
        }
    }

    for (int i = 255; i >= 0; i--){
        if (dem[i] == minFre){
            cout << (char)i << ' ' << dem[i] << endl;
            break;
        }
    }

    return 0;
}