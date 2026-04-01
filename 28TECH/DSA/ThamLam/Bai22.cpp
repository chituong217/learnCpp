#include <iostream>
#include <cmath>

using namespace std;

int main(){
    long long n;
    cin >> n;

    long long a = -1, b = -1, c = -1;
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            a = i;
            break;
        }
    }

    if (a != -1){
        for (int i = a + 1; i <= sqrt(n/a); i++){
            if ((n/a) % i == 0){
                b = i;
                break;
            }
        }
        if (b != -1){
            c = n / (a * b);
        }
    }

    if (a > 1 && b > 1 && c > 1 && a != b && b != c && a != c){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}