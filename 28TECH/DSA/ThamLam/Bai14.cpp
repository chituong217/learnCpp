#include <iostream>

using namespace std;

int main(){
    int n, m, s;
    cin >> n >> s >> m;
    // n : do an toi da mua 1 ngay
    // s : so ngay
    // m : do an an 1 ngay

    int target = m * s;
    int days = s - (s / 7);

    if (days * n < target || (s >= 7 && 6 * n < 7 * m)){
        cout << "-1";
        return 0;
    }

    int needMin = (target + n - 1) / n;
    cout << needMin;

    return 0;
}