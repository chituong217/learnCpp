#include <iostream>

using namespace std;

bool isTangChat(int a[], int n){
    for (int i = 0; i < n; i++){
        if (i == 0){
            continue;
        }
        if (a[i] <= a[i-1]){
            return false;
        }
    }
    return true;
}

int main(){
    int n; 
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    if (isTangChat(a, n) == true){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}