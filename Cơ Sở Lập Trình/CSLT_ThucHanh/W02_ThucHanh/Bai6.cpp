#include <iostream>

using namespace std;

int main(){
    double gpa;
    cin >> gpa;
    char rank;
    if (gpa >= 8.5){
        rank = 'A';
    }
    else if (gpa >= 7.5){
        rank = 'B';
    }
    else if (gpa >= 5.5){
        rank = 'C';
    }
    else if (gpa >= 4.0){
        rank = 'D';
    }
    else{
        rank = 'F';
    }
    cout << "Rank cua ban la:" << rank << endl;

    return 0;
}