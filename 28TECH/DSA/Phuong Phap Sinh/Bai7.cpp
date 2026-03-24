#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
int a[100];
bool isFinal = false;

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
        while (a[i] > a[j]){
            j--;
        }
        swap(a[i], a[j]);
        reverse(a + 1 + i, a + 1 + n);
    }
}

int main(){
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    khoitao();
    while(isFinal == false){
        for (int i = 1; i <= n; i++){
            cout << v[a[i] - 1] << ' ';
        }
        cout << endl;
        sinh();
    }

    return 0;
}