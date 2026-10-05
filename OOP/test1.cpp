#include <bits/stdc++.h>

using namespace std;

class Section{
private:
    int capacity;
    vector<string> enrolledStudents;
public:
    Section(int capacity){
        if (capacity <= 0){
            cout << "Loi si so !\n";
            this->capacity = 0;
        }
        else this->capacity = capacity;
    }
    bool enroll(string studentName){
        if (enrolledStudents.size() < capacity && find(enrolledStudents.begin(), enrolledStudents.end(), studentName) == enrolledStudents.end()){
            enrolledStudents.push_back(studentName);
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){


    return 0;
}