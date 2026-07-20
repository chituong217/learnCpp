#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool comp(int a, int b){
    if (abs(a) < abs(b)){
        return true;
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    stable_sort(a.begin(), a.end(), comp);
    for (int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }
    return 0;
}