#include <iostream>

using namespace std;

long long calculateSequence(int n){
    if (n == 0){
        return 1;
    }
    else if (n == 1){
        return 2;
    }
    else{
        return 2 * calculateSequence(n - 1) + 3 * calculateSequence(n - 2);
    }
}