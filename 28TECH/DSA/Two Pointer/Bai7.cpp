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
    long long cnt = 0, sum = 0;

    for (int end = 0; end < n; end++){
        sum += a[end];
        
        while (sum >= s){
            cnt += n - end;
            sum -= a[start];
            start++;
        }
    }

    cout << cnt;

    return 0;
}