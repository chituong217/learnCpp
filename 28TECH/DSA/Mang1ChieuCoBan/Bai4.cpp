#include <iostream>

using namespace std;

int main(){
    int n, x;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> x;

    int cntLarger = 0, cntSmaller = 0;
    for (int i = 0; i < n; i++){
        if (a[i] > x){
            cntLarger++;
        }
        else if (a[i] < x){
            cntSmaller++;
        }
    }

    cout << cntSmaller << endl;
    cout << cntLarger << endl;

    return 0;
}