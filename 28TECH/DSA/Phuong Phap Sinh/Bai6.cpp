#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
bool isFinal = false;
vector<int> a(100);

void khoitao(){
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
        while (a[j] < a[i]){
            j--;
        }
        swap(a[i], a[j]);
        reverse(a.begin() + 1 + i, a.begin() + 1 + n);
    }
}

int main(){
    cin >> n;

    khoitao();
    vector<vector<int>> v;
    while(isFinal == false){
        v.push_back(a);
        sinh();
    }

    for (auto it = v.rbegin(); it != v.rend(); it++){
        for (int i = 1; i <= n; i++){
            cout << (*it)[i];
        }
        cout << '\n';
    }

    return 0;
}