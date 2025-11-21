#include <iostream>
using namespace std;

struct Student{
    int id;
    double gpa;
};

void inputStudent(Student &st){
    cin >> st.id;
    cin >> st.gpa;
}
