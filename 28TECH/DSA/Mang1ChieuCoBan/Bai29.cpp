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

    int maxFre = 0;
    for (int i = 0; i < n; i++){
        if (dem[a[i]] > maxFre){
            maxFre = dem[a[i]];
        }
    }

    for (int i = 0; i < 1000001; i++){
        if (dem[i] == maxFre){
            cout << i << ' ' << dem[i];
            break;
        }
    }

    return 0;
}