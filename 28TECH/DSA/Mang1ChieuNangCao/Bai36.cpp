#include <iostream>
#include <map>

using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n + 1];
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    map<long long, int> mp;

    bool ok = false;
    long long sum = 0;
    for (int i = 1; i <= n; i++){
        sum += a[i];

        if (mp.find(sum) != mp.end() || sum == 0){
            ok = true;
            break;
        }

        mp[sum] = i;
    }

    if (ok == true){
        cout << "1";
    }
    else{
        cout << "-1";
    }

    return 0;
}