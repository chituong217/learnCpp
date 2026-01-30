#include <iostream>

using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    bool isFound = false;
    int i_del = -1;
    for (int i = 0; i < n; i++){
        if (a[i] == x){
            isFound = true;
            i_del = i;
            break;
        }
    }

    if (isFound == false){
        cout << "NOT FOUND";
    }
    else{
        for (int i = i_del; i < n - 1; i++){
            a[i] = a[i + 1];
        }
        n--;
        for (int i = 0; i < n; i++){
            cout << a[i] << ' ';
        }
    }

    return 0;
}