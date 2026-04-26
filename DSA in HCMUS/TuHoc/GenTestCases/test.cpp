#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <algorithm>

using namespace std;

int main(){
    random_device rd;
    mt19937 rng(rd());

    uniform_int_distribution<int> khuon_so(INT_MIN, INT_MAX);

    cout << "Quay so ngau nhien : \n";
    for (int i = 0; i < 5; i++){
        cout << khuon_so(rng) << " ";
    }
    return 0;
}