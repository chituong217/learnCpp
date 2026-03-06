#include <iostream>

using namespace std;

int a[10000005];
int dem[3];

int main(){
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 0; i < n; i++){
        dem[a[i]]++;
    }

    for (int i = 0; i < 3; i++){
        while (dem[i] > 0){
            cout << i << ' ';
            dem[i]--;
        }
    }

    return 0;
}