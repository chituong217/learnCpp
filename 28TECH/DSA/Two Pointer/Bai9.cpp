#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    multiset<int> se;

    int start = 0;
    long long cnt = 0;

    for (int end = 0; end < n; end++){
        se.insert(a[end]);
        int diff = 0;
        if (se.empty() == false){
            diff = *(se.rbegin()) - *(se.begin());
        }

        while (diff > k){
            auto it = se.find(a[start]);
            if (it != se.end()){
                se.erase(it);
            }
            start++;

            if (se.empty() == false){
                diff = *(se.rbegin()) - *(se.begin());
            }
        }

        cnt += end - start + 1;
    }

    cout << cnt;

    return 0;
}