#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int max1 = INT_MIN;
    int i_max1 = -1;
    int max2 = INT_MIN;

    for (int i = 0; i < n; i++){
        if (a[i] > max1){
            max1 = a[i];
            i_max1 = i;
        }
    }

    for (int i = 0; i < n; i++){
        if (i != i_max1 && a[i] > max2){
            max2 = a[i];
        }
    }

    cout << max1 << ' ';
    cout << max2 << endl;

    return 0;
}