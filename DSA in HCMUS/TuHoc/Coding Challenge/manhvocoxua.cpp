#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string s;
    
    cin >> n >> s;
    int dem[256] = {0};
    for (int i = 0; i < (int)s.size(); i++){
        dem[(int)s[i]]++;
    }

    int maxFre = 0;
    char res;
    for (int i = 0; i < 256; i++){
        if (dem[i] > maxFre){
            maxFre = dem[i];
            res = (char)i;
        }
    }

    cout << res;

    return 0;
}