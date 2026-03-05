#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;

    int dem[256] = {0};
    for (int i = 0; i < s.size(); i++){
        dem[s[i]] = 1;
    }

    int demcon[256] = {0};
    int left = 0;
    for (int right = 0; right < n; right++){
        demcon[s[right]]++;

        
    }


    return 0;
}