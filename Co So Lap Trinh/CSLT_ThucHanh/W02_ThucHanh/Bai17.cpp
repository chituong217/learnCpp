#include <iostream>
using namespace std;

int main(){
    int capacity, users;
    cin >> capacity >> users;
    double giveaway = 0.5 * users;
    if (giveaway < 16){
        capacity -= giveaway;
    }
    else{
        capacity -=16;
    }
    cout << capacity;
    return 0;
}