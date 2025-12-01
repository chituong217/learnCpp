#include <iostream>

using namespace std;

void printMultiplicationTable(int range, int num){
    for (int i = 1; i <= range; i++){
        cout << num << " * " << i << " = " << num*i << endl;
    }
}

int main(){
    printMultiplicationTable(10, 5);
    return 0;
}