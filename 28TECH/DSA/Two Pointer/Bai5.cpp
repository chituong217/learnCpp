#include <iostream>

using namespace std;

int main(){
    int n, s;
    cin >> n >> s;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int start = 0, end = 0, curr_cnt = 0, min_cnt = INT_MAX;
    long long curr_carried = 0;

    while (end < n){
        curr_carried += a[end];
        end++;
        curr_cnt++;

        while (curr_carried >= s){
            if (curr_cnt < min_cnt){
                min_cnt = curr_cnt;
            }

            curr_carried -= a[start];
            start++;
            curr_cnt--;
        }
    }

    if (min_cnt == INT_MAX){
        cout << "-1";
    }
    else{
        cout << min_cnt;
    }

    return 0;
}