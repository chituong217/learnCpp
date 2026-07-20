#include <iostream>
using namespace std;

struct Student{
    int id;
    double gpa;
};

void gpaBelow5(Student a[], int n, Student b[], int &nb){
    int nb = 0;
    for (int i=0; i<n; i++){
        if (a[i].gpa < 5){
            b[nb] = a[i];
            nb++;
        }
    }
}
