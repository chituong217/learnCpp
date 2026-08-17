#include <bits/stdc++.h>

using namespace std;

class Person{
protected:
    string ten, ngaysinh, diachi;
public:
    Person(string ten, string ngaysinh, string diachi){
        this->ten = ten;
        this->ngaysinh = ngaysinh;
        this->diachi = diachi;
    }
    Person(){
        ten = "";
        ngaysinh = "";
        diachi = "";
    }
    void in(){
        cout << ten << ' ' << ngaysinh << ' ' << diachi << ' ';
    }
};

class Student : public Person{
private:
    static int dem;
    string masv, lop;
    double gpa;
public:
    Student(){
        dem++;

        string tmp = to_string(dem);
        while (tmp.size() < 4){
            tmp = "0" + tmp;
        }

        this->masv = tmp;
    }

    void in(){
        cout << masv << ' ';
        Person::in();
        cout << lop << ' ' << fixed << setprecision(2) << gpa << endl;
    }

    void standardizeDate();
    void standardizeName();

    friend istream& operator >> (istream &in, Student &x){
        in >> ws;
        getline(in, x.ten);
        // xu li ngaysinh, diachi
        string tmp;
        getline(in, tmp);
        int i = 0;
        while (i < (int)tmp.size()){
            if (isdigit(tmp[i]) || tmp[i] == '/'){
                i++;
            }
            else{
                break;
            }
        }

        x.ngaysinh = tmp.substr(0, i);
        x.diachi = tmp.substr(i + 1, tmp.size());

        getline(in, x.lop);
        in >> x.gpa;

        x.standardizeName();
        x.standardizeDate();

        return in;
    }
};

int Student::dem = 0;

void Student::standardizeDate(){
    int n = ngaysinh.size();
    for (int i = 0; i < n; i++){
        if (ngaysinh[i] == '/') ngaysinh[i] = ' ';
    }

    stringstream ss(ngaysinh);
    string word;
    string newDate = "";

    ss >> word;
    if (word.size() == 1){
        newDate += "0";
    }
    newDate += word;
    newDate += "/";

    ss >> word;
    if (word.size() == 1){
        newDate += "0";
    }
    newDate += word;
    newDate += "/";

    ss >> word;
    if (word.size() == 1){
        newDate += "000";
    }
    else if (word.size() == 2){
        newDate += "00";
    }
    else if (word.size() == 3){
        newDate += "0";
    }
    newDate += word;
    
    ngaysinh = newDate;
}

void Student::standardizeName(){
    string newName = "";
    
    stringstream ss(this->ten);
    string word;

    while (ss >> word){
        for (int i = 0; i < (int)word.size(); i++){
            if (i == 0) word[i] = toupper(word[i]);
            else word[i] = tolower(word[i]);
        }

        newName += word;
        newName += ' ';
    }

    newName.pop_back();
    this->ten = newName;
}

int main(){
    int n;
    cin >> n;

    vector<Student> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    for (int i = 0; i < n; i++){
        v[i].in();
    }

    return 0;
}