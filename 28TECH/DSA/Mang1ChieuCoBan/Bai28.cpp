#include <iostream>

using namespace std;

int dem[1000001];

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        dem[a[i]]++;
    }

    for (int i = 0; i < n; i++){
        if (dem[a[i]] > 0){
            cout << a[i] << ' ' << dem[a[i]] << endl;
            dem[a[i]] = 0;
        }
    }

    return 0;
}