#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int left  = 0, right = n - 1;
    while (left <= right){
        int tmp = a[left];
        a[left] = a[right];
        a[right] = tmp;

        left++;
        right--;
    }

    for (int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }

    return 0;
}