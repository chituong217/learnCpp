#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> a;
bool isFinal = false;

void khoitao(){
    a[0] = 0;
    for (int i = 1; i <= k; i++){
        a[i] = i;
    }

}

void sinh(){
    int i = k;
    
    while (i >= 1 && a[i] == (n - k + i)){
        i--;
    }

    if (i == 0){
        isFinal = true;
    }
    else{
        a[i]++;
        for (int j = i + 1; j <= k; j++){
            a[j] = a[j - 1] + 1;
        }
    }
}

int main(){
    cin >> n >> k;
    a.resize(k + 1);

    vector<int> target(k + 1);
    target[0] = 0;
    for (int i = 1; i <= k; i++){
        cin >> target[i];
    }

    vector<vector<int>> v;
    khoitao();

    while(isFinal == false){
        v.push_back(a);
        sinh();
    }

    reverse(v.begin(), v.end());
    for (int i = 0; i < (int)v.size(); i++){
        if (v[i] == target){
            cout << i + 1;
            break;
        }
    }

    return 0;
}