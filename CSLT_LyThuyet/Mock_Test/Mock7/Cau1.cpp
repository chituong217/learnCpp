#include <iostream>

using namespace std;

int pascal(int n, int k){
    if (k == 0 || k == n){
        return 1;
    }

    return pascal(n-1, k) + pascal(n-1, k-1);
}
