#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> a(100);
bool isFinal = false;

void khoitao(){
    a[0] = 0;
    for (int i = 1; i <= n; i++){
        a[i] = i;
    }
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
        reverse(a.begin() + 1 + i, a.begin() + 1 + n);
    }
}

int main(){
    cin >> n;
    vector<int> target(100);
    target[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> target[i];
    }

    vector<vector<int>> v;
    khoitao();
    while (isFinal == false){
        v.push_back(a);
        sinh();
    }

    for (int i = 0; i < (int)v.size(); i++){
        bool ok = true;
        for (int j = 1; j <= n; j++){
            if (v[i][j] != target[j]){
                ok = false; 
                break;
            }
        }

        if (ok == true){
            cout << i + 1;
            break;
        }
    }

    return 0;
}