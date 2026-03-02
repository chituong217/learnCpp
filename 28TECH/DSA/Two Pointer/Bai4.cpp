#include <iostream>

using namespace std;

int main(){
    int n, s;
    cin >> n >> s;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int start = 0, end = 0, max_cnt = 0, curr_cnt = 0;
    long long curr_carried = 0;
    while (end < n){
        curr_carried += a[end];
        curr_cnt++;
        end++;

        while (curr_carried > s){
            curr_carried -= a[start];
            start++;
            curr_cnt--;
        }

        if (curr_cnt > max_cnt){
            max_cnt = curr_cnt;
        }
    }

    cout << max_cnt;

    return 0;
}