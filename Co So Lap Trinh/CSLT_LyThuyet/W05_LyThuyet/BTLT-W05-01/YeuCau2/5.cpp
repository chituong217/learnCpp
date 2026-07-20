#include <iostream>
using namespace std;

struct Student{
    int id;
    double gpa;
};

void outputArray(Student a[], int n){
    for (int i=0; i<n; i++){
        cout << "Id cua sinh vien la : " << a[i].id << endl;
        cout << "GPA cua sinh vien la : " << a[i].gpa << endl;
    }
}