#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    long long mangFibo[92];
    mangFibo[0] = 0;
    mangFibo[1] = 1;
    for (int i = 2; i < 92; i++){
        mangFibo[i] = mangFibo[i - 1] + mangFibo[i - 2];
    }

    bool isExisted = false;
    for (int i = 0; i < n; i++){
        bool isFibo = false;
        for (int j = 0; j < 92; j++){
            if (a[i] == mangFibo[j]){
                isFibo = true;
                isExisted = true;
                break;
            }
            else if (mangFibo[j] > a[i]){
                break;
            }
        }
        if (isFibo == true){
            cout << a[i] << ' ';
        }
    }

    if (isExisted == false){
        cout << "NONE";
    }

    return 0;
}