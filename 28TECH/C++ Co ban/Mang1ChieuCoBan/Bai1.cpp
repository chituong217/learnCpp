#include <iostream>
#define MAX_LEN 1000
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[MAX_LEN];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    int cntChan = 0, cntLe = 0, sumChan = 0, sumLe = 0;
    for (int i=0; i<n; i++){
        if (a[i] % 2 == 0){
            cntChan++;
            sumChan += a[i];
        }
        else{
            cntLe++;
            sumLe += a[i];
        }
    }
    cout << cntChan << endl;
    cout << cntLe << endl;
    cout << sumChan << endl;
    cout << sumLe << endl;
    return 0;
}