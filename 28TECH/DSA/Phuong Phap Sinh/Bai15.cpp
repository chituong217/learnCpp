#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, a[100];
bool isFinal = false;

void khoitao(){
    for (int i = 1; i <= n; i++){
        a[i] = i;
    }
    isFinal = false;
}

void sinh(){
    int i = n - 1;
    while (i >= 1 && a[i] > a[i + 1]){
        i--;
    }

    if (i == 0){
        isFinal = true;
    }
    else{
        int j = n;
        while (a[i] > a[j]){
            j--;
        }

        swap(a[i], a[j]);
        reverse(a + 1 + i, a + 1 + n);
    }
}

int main(){
    string s;
    cin >> s;

    vector<string> v;
    khoitao();
    while (isFinal == false){
        string tmp;
        for (int i = 1; i <= n; i++){
            tmp += s[a[i]];
        }
        v.push_back(tmp);
        sinh();
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < (int)v.size(); i++){
        cout << v[i] << '\n';
    }

    return 0;
}