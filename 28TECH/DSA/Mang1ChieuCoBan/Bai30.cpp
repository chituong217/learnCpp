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

    for (int i = 0; i < n; i++){
        if (dem[a[i]] == maxFre){
            cout << a[i] << ' ' << maxFre;
            break;
        }
    }

    return 0;
}