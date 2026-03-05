#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int tien25 = 0;
    int tien50 = 0;
    bool ok = true;

    for (int i = 0; i < n; i++){
        if (a[i] == 25){
            tien25++;
        }
        else if (a[i] == 50){
            if (tien25 > 0){
                tien25--;
                tien50++;
            }
            else{
                ok = false;
                break;
            }
        }
        else if (a[i] == 100){
            if (tien50 > 0 && tien25 > 0){
                tien50--;
                tien25--;
            }
            else if (tien50 == 0 && tien25 >= 3){
                tien25 -= 3;
            }
            else{
                ok = false;
                break;
            }
        }
    }

    if (ok == true){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}