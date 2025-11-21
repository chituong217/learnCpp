#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    cout << "Note 20000: "<< (n/20000)<< endl;
    n -= (n/20000)*20000;
    cout << "Note 10000: "<< (n/10000)<< endl;
    n -= (n/10000) * 10000;
    cout << "Note 5000: "<< (n/5000)<< endl;
    n-= (n/5000) * 5000;
    cout << "Note 1000: "<< (n/1000)<< endl;
    n-= (n/1000) *1000;
    cout<< "Remain money = "<< n<< endl;
    return 0;
}