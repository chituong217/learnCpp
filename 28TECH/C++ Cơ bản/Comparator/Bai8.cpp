#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countPrime(int n){
    int cnt = 0; 
    while (n){
        int last = n % 10;
        if (last == 2 || last == 3 || last == 5 || last == 7){
            cnt++;
        }
        n /= 10;
    }
    return cnt;
}

bool comp(pair <int,int> a, pair<int,int> b){
    if (a.second > b.second){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int n;
    cin >> n;
    vector <pair<int,int>> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = countPrime(a[i].first);
    }
    stable_sort(a.begin(), a.end(), comp);
    for (int i = 0; i < n; i++){
        cout << a[i].first << ' ';
    }
    return 0;
}