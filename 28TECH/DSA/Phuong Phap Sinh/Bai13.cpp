#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, a[100];
bool isFinal = false;

void khoitao(){
    for (int i = 1; i <= n; i++){
        a[i] = 0;
    }
    isFinal = false;
}

void sinh(){
    int i = n;
    while (i >= 1 && a[i] == 1){
        a[i] = 0;
        i--;
    }

    if (i == 0){
        isFinal = true;
    }
    else{
        a[i] = 1;
    }
}

int main(){
    cin >> n;

    vector<string> v;

    khoitao();
    while (isFinal == false){
        string s;
        bool valid = false;
        for (int i = 1; i <= n; i++){
            if (a[i] == 1){
                s += (char)(i + '0');
                s += ' ';
                valid = true;
            }
        }
        if (valid == true){
            v.push_back(s);
        }
        sinh();
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < (int)v.size(); i++){
        cout << v[i] << '\n';
    }

    return 0;
}