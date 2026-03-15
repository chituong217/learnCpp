#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;

    string res = "python";

    int n = s.size();
    for (int start = 0; start + 7 <= n; start++) {
        string window = s.substr(start, 7);
        
        for (int k = 0; k < 7; k++) {
            window[k] = tolower(window[k]);
        }
        
        for (int i = 0; i < 7; i++) {
            string temp = window.substr(0, i) + window.substr(i + 1);
            if (temp == res) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO";

    return 0;
}