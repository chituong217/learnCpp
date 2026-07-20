#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int sum(int n){
    int sum = 0;
    while (n){
        sum += n%10;
        n /= 10;
    }
    return sum;
}

bool comp(int a, int b){
    if (sum(a) < sum(b)){
        return true;
    }
    else if (sum(a) == sum(b)){
        return a < b;
    }
    else{
        return false;
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end(), comp);
    for (int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }
    return 0;
}