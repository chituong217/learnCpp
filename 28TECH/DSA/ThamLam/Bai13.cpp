#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(){
    string s;   
    cin >> s;

    int n = s.size();

    int dem[256] = {0};
    for (int i = 0; i < (int)s.size(); i++){
        dem[(int)s[i]]++;
    }

    int maxFre = 0;
    for (int i = 0; i < 256; i++){
        if (dem[i] > 0){
            maxFre = max(maxFre, dem[i]);
        }
    }

    if (maxFre > (n + 1)/2){
        cout << "NO";
    }
    else{
        cout << "YES";
    }

    return 0;
}