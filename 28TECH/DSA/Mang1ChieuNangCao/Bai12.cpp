#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool isPrime(int n){
    for (int i = 2; i*i <= n; i++){
        if (n % i == 0){
            return false;
        }
    }

    return n > 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tmp;
    vector<int> v;
    map<int, int> mp;
    
    while(cin >> tmp){
        v.push_back(tmp);
        if (isPrime(tmp) == true){
            mp[tmp]++;
        }
    }

    for (auto it = v.begin(); it != v.end(); it++){
        if (mp[*it] > 0){
            cout << *it << ' ' << mp[*it] << '\n';
            mp[*it] = 0;
        }
    }

    return 0;
}