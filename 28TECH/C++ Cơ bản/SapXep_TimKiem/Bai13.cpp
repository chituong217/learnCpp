#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());

    int slgachconcothexep = a[0];
    int cnt = 1;
    for (int i = 1; i < n; i++){
        if (slgachconcothexep == 0){
            break;
        }
        slgachconcothexep--;
        if (slgachconcothexep > a[i]){
            slgachconcothexep = a[i];
        }
        cnt++;
    }
    cout << cnt;
    return 0;
}