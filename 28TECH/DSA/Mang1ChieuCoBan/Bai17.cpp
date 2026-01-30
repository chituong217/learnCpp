#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int left = 0, right = n - 1;
    bool ok = true;

    while (left <= right){
        if (a[left] != a[right]){
            ok = false;
            break;
        }
        left++;
        right--;
    }

    if (ok == true){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}