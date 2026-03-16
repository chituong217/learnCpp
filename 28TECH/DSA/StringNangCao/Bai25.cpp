#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int m, s;
    cin >> m >> s;

    int s2 = s;

    if (s == 0){
        if (m == 1){
            cout << '0' << endl;
            cout << '0';
        }
        else{
            cout << "NOT FOUND";
        }
        return 0;
    }

    if (s > m * 9 || m < 1){
        cout << "NOT FOUND";
        return 0;
    }

    string lonNhat, nhoNhat;

    int cnt = 0;
    while (s >= 9){
        lonNhat += '9';
        s -= 9;
        cnt++;
    }

    while (cnt < m){
        lonNhat += to_string(s);
        s -= s;
        cnt++;
    }

    if (cnt > m){
        cout << "NOT FOUND";
        return 0;
    }

    nhoNhat.resize(m);

    for (int i = 0; i < m; i++){
        int digit;
        if (i == 0){
            digit = max(1, s2 - 9 * (m - 1));
        }
        else{
            digit = max(0, s2 - 9 * (m - i - 1));
        }
        nhoNhat[i] = (char)('0' + digit);
        s2 -= digit;
    }

    cout << nhoNhat << endl;
    cout << lonNhat;

    return 0;
}