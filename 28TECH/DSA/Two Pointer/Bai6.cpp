#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int start = 0;
    long long sum = 0, cnt = 0;
    for (int end = 0; end < n; end++){
        sum += a[end];

        while (sum > s && start <= end){
            sum -= a[start];
            start++;
        }

        if (sum <= s){
            cnt += end - start + 1;
        }

    }

    cout << cnt;


    return 0;
}