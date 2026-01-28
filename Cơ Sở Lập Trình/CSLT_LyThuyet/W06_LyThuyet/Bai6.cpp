#include <iostream>
#include <string.h>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cctype>

using namespace std;

#define MAX_STUDENTS 100
#define MAX_CHAR 501
#define MAX_LINE 1001

struct Student{
    char id[MAX_CHAR];
    char name[MAX_CHAR];
    double gpa;
};

void xuat(ostream &out, const char id[], const char name[], double gpa){
    out << id << "|" << name << "|" << gpa << endl;
}

void split(char c[], char name[], char id[]){
    const char delimeter[] = "|";
    char *token = strtok(c, delimeter);
    if (token != NULL) {
        strcpy(name, token);
    }
    token = strtok(NULL, delimeter);
    if (token != NULL) {
        strcpy(id, token);
    }
}

void capitalizeFisrtCharacter(char c[]){
    char ans[MAX_CHAR] = "";
    char temp_c[MAX_CHAR];
    strcpy(temp_c, c);

    char *word = strtok(temp_c, " ");
    bool is_first_word = true;

    while (word != NULL){
        if (word[0] != '\0') {
            word[0] = toupper(word[0]);
        }
        
        if (!is_first_word) {
            strcat(ans, " ");
        }
        strcat(ans, word);
        is_first_word = false;

        word = strtok(NULL, " ");
    }
    strcpy(c, ans);
}


bool docSinhVien(istream &in, Student &s) {
    char lineNameID[MAX_LINE];
    char linePoints[MAX_LINE];
    
    if (!in.getline(lineNameID, MAX_LINE)) return false;
    if (!in.getline(linePoints, MAX_LINE)) return false;
    
    char tempNameID[MAX_LINE]; 
    strcpy(tempNameID, lineNameID);
    split(tempNameID, s.name, s.id); 
    
    capitalizeFisrtCharacter(s.name);
    
    char *pointToken = strtok(linePoints, " ");
    double sumPoints = 0.0;
    int numPoints = 0;
    
    while (pointToken != NULL) {
        sumPoints += atof(pointToken);
        numPoints++;
        pointToken = strtok(NULL, " ");
    }
    
    s.gpa = sumPoints / (double)numPoints;
    
    return true;
}


void sapXep(Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].gpa < arr[j+1].gpa) {
                Student temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    const char *pathIn = "STUDENT.TXT";
    const char *pathOut = "GPA.TXT";

    Student students[MAX_STUDENTS];
    int numStudents = 0;

    ifstream fIn;
    fIn.open(pathIn);
    if (!fIn.is_open()){
        cout << "Khong the doc file" << endl;
        return 1;
    }
    
    while (docSinhVien(fIn, students[numStudents]) && numStudents < MAX_STUDENTS) {
        numStudents++;
    }
    fIn.close();

    sapXep(students, numStudents); 

    ofstream fOut;
    fOut.open(pathOut);
    if (!fOut.is_open()){
        cout << "Khong the ghi file" << endl;
        return 1;
    }
    
    fOut << fixed << setprecision(1);
    for (int i = 0; i < numStudents; i++) {
        xuat(fOut, students[i].id, students[i].name, students[i].gpa);
    }
    
    fOut.close();

    return 0;
}