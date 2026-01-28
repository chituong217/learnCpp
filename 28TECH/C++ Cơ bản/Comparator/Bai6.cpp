#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int countOddNumber(int n){
    int cnt = 0;
    while (n){
        if ((n%10) % 2 == 1){
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
    else if (a.second == b.second){
        return a.first < b.first;
    }
    else{
        return false;
    }
}

int main()
{   
    int n;
    cin >> n;
    vector <pair<int,int>> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = countOddNumber(a[i].first);
    }
    sort(a.begin(), a.end(), comp);
    for (int i = 0; i < n; i++){
        cout << a[i].first << ' ';
    }
    return 0;
}