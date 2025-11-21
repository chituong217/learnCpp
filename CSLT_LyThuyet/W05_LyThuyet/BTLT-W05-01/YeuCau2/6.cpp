#include <iostream>
using namespace std;

struct Student{
    int id;
    double gpa;
};

Student maxGPA(Student a[], int n){
    double max = a[0].gpa;
    Student maxGPA = a[0];
    for(int i=0; i<n; i++){
        if (a[i].gpa > max){
            max = a[i].gpa;
            maxGPA = a[i];
        }
        else if (a[i].gpa == max){
            if (a[i].id > maxGPA.id){
                maxGPA = a[i];
            }
        }
    }
    return maxGPA;
}
