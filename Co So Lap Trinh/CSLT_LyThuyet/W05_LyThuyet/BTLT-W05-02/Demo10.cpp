#include <iostream>
#include <fstream>
using namespace std;

struct Student{
    int id;
    char name[101];
    int age;
    char address[101];
};

void loadStudent(ifstream &f, Student &st);
void loadStudentArray(ifstream &f, Student a[], int &n);
void printStudent(Student st);
void printStudentArray(Student a[], int n);

int main(int argc, const char * argv[]) {
    Student a[100];
    int n = 0;
    ifstream f;
    
    f.open("D:\\studentarray-input.txt");
    
    if(!f.is_open()){
        cout << "Khong the mo file" << endl;
    }
    else{
        loadStudentArray(f, a, n);
        printStudentArray(a, n);
        f.close();
    }
    return 0;
}

void loadStudent(ifstream &f, Student &st){
    f >> st.id;
    f.getline(st.name, 101);
    f.getline(st.name, 101);
    // st.name[strlen(st.name) - 1] = '\0';
    f >> st.age;
    f.getline(st.address, 101);
    f.getline(st.address, 101);
    // st.address[strlen(st.address) - 1] = '\0';
}
void loadStudentArray(ifstream &f, Student a[], int &n){
    f >> n;
    for(int i = 0; i < n; i++){
        loadStudent(f, a[i]);
    }
}
void printStudent(Student st){
    cout << "ID: " << st.id << endl;
    cout << "Name: " << st.name << endl;
    cout << "Age: " << st.age << endl;
    cout << "Address: " << st.address << endl;
}
void printStudentArray(Student a[], int n){
    cout << "Number of elements: " << n << endl;
    for(int i = 0; i < n; i++){
        cout << "a[" << i << "]: " << endl;
        printStudent(a[i]);
    }
}