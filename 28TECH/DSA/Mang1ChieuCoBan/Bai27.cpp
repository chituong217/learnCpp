#include <iostream>

using namespace std;

int dem[1000005] = {0};

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        dem[a[i]]++;
    }

    for (int i = 0; i <= 1000000; i++){
        if (dem[i] > 0){
            cout << i << ' ' << dem[i] << endl;
        }
    }

    return 0;
}