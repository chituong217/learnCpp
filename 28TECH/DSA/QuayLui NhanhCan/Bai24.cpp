#include <iostream>
#include <string>

using namespace std;

string s;
int n;
int X[100];

// 0 la in hoa
// 1 la in thuong

void in(){
    for (int i = 1; i <= n; i++){
        if (isalpha(s[i - 1])){
            if (X[i] == 0){
                cout << (char)toupper(s[i - 1]);
            }
            else{
                cout << (char)tolower(s[i - 1]);
            }
        }
        else{
            cout << s[i - 1];
        }
    }
    cout << '\n';
}

void Try(int i){
    if (isalpha(s[i - 1])){
        for (int j = 0; j <= 1; j++){
            X[i] = j;

            if (i == n){
                in();
            }
            else{
                Try(i + 1);
            }
        }
    }
    else{
        X[i] = 0;
        if (i == n){
            in();
        }
        else{
            Try(i + 1);
        }
    }
}

int main(){
    cin >> s;
    n = s.size();

    Try(1);

    return 0;
}