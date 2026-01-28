#include <iostream>
using namespace std;

struct Student{
    int id;
    double gpa;
};

void outputStudent(Student st){
    cout << "Id cua sinh vien la : " << st.id << endl;
    cout << "GPA cua sinh vien la : " << st.gpa << endl;
}
