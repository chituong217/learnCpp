#include <iostream>
#include <set>
#include <vector>
#include <iomanip>

using namespace std;

int main(){
    int n, I;
    cin >> n >> I;
    set<int> se;
    for (int i = 0; i < n; i++){
        int tmp; cin >> tmp;
        se.insert(tmp);
    }
    double d = 0;
    for (auto it = se.begin(); it != se.end(); it++){
        auto itsau = it;
        itsau++;
        if (itsau == se.end()){
            break;
        }
        double tmp_d = (1.0*(*itsau) - 1.0*(*it))/2.0;
        if (tmp_d > d){
            d = tmp_d;
        }
    }
    if (*(se.begin()) != 0){
        double tmp_d = *(se.begin());
        if (tmp_d > d){
            d = tmp_d;
        }
    }
    if (*(se.rbegin()) != I){
        double tmp_d = I - *(se.rbegin());
        if (tmp_d > d){
            d = tmp_d;
        }
    }
    cout << fixed << setprecision(10) << d;

    return 0;
}