#include <iostream>
using namespace std;

struct Student{
    int id;
    double gpa;
};

void sortAscByID(Student a[], int n){
    for (int i=0; i<n; i++){
        int min_pos = i;
        for (int j = i+1; j < n ; j++){
            if (a[j].id < a[min_pos].id){
                min_pos = j;
            }
        }
        Student tmp = a[i];
        a[i] = a[min_pos];
        a[min_pos] = tmp;
    }
}
