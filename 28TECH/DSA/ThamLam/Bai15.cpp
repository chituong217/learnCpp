#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int s, d;
    cin >> s >> d;
    // tong s
    // so chu so d
    if (9 * d < s){
        cout << "-1";
        return 0;
    }

    vector<int> v(d);
    for (int i = 0; i < d; i++){
        v[i] = 0;
    }

    int du = s;
    int i = d - 1;
    while (du > 1){
        if (v[i] < 9){
            v[i]++;
            du--;
        }
        else{
            i--;
        }
    }
    v[0] += du;

    for(int j = 0; j < d; j++){
        cout << v[j];
    }

    return 0;
}