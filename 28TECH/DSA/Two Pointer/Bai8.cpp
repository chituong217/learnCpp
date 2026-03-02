#include <iostream>
#include <vector>

using namespace std;

int dem[1000005];

int main(){
    int n, k;
    cin >> n >> k;
    
    vector <int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int start = 0, diffs = 0;
    long long cnt = 0;
    for (int end = 0; end < n; end++){
        if (dem[a[end]] == 0){
            diffs++;
        }
        dem[a[end]]++;
        

        while (diffs > k && start <= end){
            dem[a[start]]--;
            if (dem[a[start]] == 0){
                diffs--;
            }
            start++;
        }

        if (diffs <= k){
            cnt += end - start + 1;
        }
    }

    cout << cnt;

    return 0;
}