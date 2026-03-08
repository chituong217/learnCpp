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
    mp[0] = 0;

    bool ok = false;
    int left, right;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 1; i <= n; i++){
        sum += a[i];

        if (mp.find(sum) != mp.end()){
            ok = true;

            if (i - mp[sum] > maxLen){
                maxLen = i - mp[sum];
                left = mp[sum] + 1;
                right = i;
            }
        }

        if (mp.find(sum) == mp.end()){
            mp[sum] = i;
        }
    }

    if (ok == true){
        for (int i = left; i <= right; i++){
            cout << a[i] << ' ';
        }
    }
    else{
        cout << "NOT FOUND";
    }

    return 0;
}