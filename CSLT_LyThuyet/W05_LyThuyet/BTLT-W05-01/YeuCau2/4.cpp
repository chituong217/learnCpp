#include <iostream>
using namespace std;

struct Student{
    int id;
    double gpa;
};

void inputArray(Student a[], int &n){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i].id;
        cin >> a[i].gpa;
    }
}
