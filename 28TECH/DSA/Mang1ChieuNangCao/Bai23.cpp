#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n], b[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }

    sort(a, a + n);
    sort(b, b + n, greater<int>());

    int indexA = 0, indexB = 0;
    for (int i = 0; i < 2 * n; i++){
        if (i % 2 == 0){
            cout << a[indexA] << ' ';
            indexA++;
        }
        else{
            cout << b[indexB] << ' ';
            indexB++;
        }
    }

    return 0;
}