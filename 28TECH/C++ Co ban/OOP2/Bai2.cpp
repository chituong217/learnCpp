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
        
        getline(in, x.ngaysinh);
        getline(in, x.diachi);

        getline(in, x.lop);
        in >> x.gpa;

        x.standardizeName();
        x.standardizeDate();

        return in;
    }

    bool operator < (Student khac){
        stringstream ss1(this->ten);
        string token;

        vector<string> namev1;
        while (ss1 >> token){
            namev1.push_back(token);
        }

        stringstream ss2(khac.ten);
        vector<string> namev2;
        while (ss2 >> token){
            namev2.push_back(token);
        }

        string ho1, dem1, ten1, ho2, dem2, ten2;

        int n1 = namev1.size(), n2 = namev2.size();
        for (int i = 0; i < n1; i++){
            if (i == 0){
                ho1 = namev1[i];
            }
            else if (i == n1 - 1){
                ten1 = namev1[i];
            }
            else if (i == 1){
                dem1 = namev1[i];
            }
            else{
                dem1 = dem1 + " " + namev1[i];
            }
        }

        for (int i = 0; i < n2; i++){
            if (i == 0){
                ho2 = namev2[i];
            }
            else if (i == n2 - 1){
                ten2 = namev2[i];
            }
            else if (i == 1){
                dem2 = namev2[i];
            }
            else{
                dem2 = dem2 + " " + namev2[i];
            }
        }

        if (ten1 < ten2) return true;
        else if (ten1 > ten2) return false;
        else{
            if (ho1 < ho2) return true;
            else if (ho1 > ho2) return false;
            else{
                if (dem1 < dem2) return true;
                else if (dem1 > dem2) return false;
                else{
                    return this->masv < khac.masv;
                }
            }
        }
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

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++){
        v[i].in();
    }

    return 0;
}