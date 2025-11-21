#include <iostream>
#include <iomanip>
#include <cmath>
#define MAX_LEN 1000
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[MAX_LEN];
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    int x; cin >> x;
    int cntBe = 0, cntLon = 0;
    for (int i=0; i<n; i++){
        if (a[i] > x){
            cntLon++;
        }
        else if (a[i] < x){
            cntBe++;
        }
    }
    cout << cntBe << endl;
    cout << cntLon << endl;
    return 0;
}