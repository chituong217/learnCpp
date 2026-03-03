#include <iostream>
#include <algorithm>

using namespace std;


int main(){
    int n, k;
    cin >> n >> k;

    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    bool ok = false;
    sort(a, a + n);
    
    for (int i = 0; i < n; i++){
        int left = i + 1, right = n - 1;
        int found = k - a[i];

        while (left < right){
            if (a[left] + a[right] == found){
                ok = true;
                break;
            }
            else if (a[left] + a[right] < found){
                left++;
            }
            else{
                right--;
            }
        }

    }

    if (ok == true){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}