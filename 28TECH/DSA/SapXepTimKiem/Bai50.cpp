#include <iostream>

using namespace std;

bool check (int n, int x, int y, int time){
    return time/x + time/y >= n;
}

int main(){
    int n, x, y;
    cin >> n >> x >> y;

    int time = 0;

    // in ra to dau tien
    if (x < y){
        time += x;
    }
    else{
        time += y;
    }

    // truong hop n = 1
    if (n == 1){
        cout << time;
        return 0;
    }
    n--;

    int left = 1, right = min(x,y) * n;
    int ans = 0;
    while (left <= right){
        int mid = (left + right)/2;

        if (check(n, x, y, mid) == true){
            ans = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }

    cout << time + ans;

    return 0;
}