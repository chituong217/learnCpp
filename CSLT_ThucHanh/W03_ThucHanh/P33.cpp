#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    double sum = 2;
    for (int i=1; i<=n; i++){
        if (i==1){
            sum = sqrt(sum);
        }
        else{
           sum = sqrt(2 + sum); 
        }
    }
    cout << fixed << setprecision(2) << sum;
    return 0;
}