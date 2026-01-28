#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector <pair <int, int>> a;
    for (int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        a.push_back({tmp, i});
    }
    sort(a.begin(), a.end());
    int cnt = 1;
    for (int i = 1; i < n; i++){
        if (a[i-1].second > a[i].second){
            cnt++;
        }
    }
    cout << cnt;
    return 0;  
}