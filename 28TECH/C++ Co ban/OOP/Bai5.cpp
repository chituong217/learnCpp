#include <bits/stdc++.h>

using namespace std;

class NV{
private:
    string manv;
    string hoten, gioitinh, ngaysinh, diachi, masothue, ngaykyhopdong;
public:
    friend istream& operator >> (istream &in, NV &x){
        getline(in, x.hoten);
        getline(in, x.gioitinh);
        getline(in, x.ngaysinh);
        getline(in, x.diachi);
        getline(in, x.masothue);
        getline(in, x.ngaykyhopdong);

        return in;
    }

    friend ostream& operator << (ostream &out, NV x){
        out << x.manv << " " << x.hoten << " " << x.gioitinh << " " << x.ngaysinh << " " << x.diachi << " " << x.masothue << " " << x.ngaykyhopdong << endl;
        
        return out;
    }

    void setMaNV(string manv);
    void standardizeDate();
    void standardizeKyHopDong();
    void standardizeName();
};

void NV::setMaNV(string manv){
    this->manv = manv;
}

void NV::standardizeDate(){
    string newDate = "";
    int n = this->ngaysinh.size();
    for (int i = 0; i < n; i++){
        if (this->ngaysinh[i] == '/'){
            this->ngaysinh[i] = ' ';
        }
    }

    stringstream ss(this->ngaysinh);
    string word;

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

    this->ngaysinh = newDate;
}

void NV::standardizeKyHopDong(){
    string newDate = "";
    int n = this->ngaykyhopdong.size();
    for (int i = 0; i < n; i++){
        if (this->ngaykyhopdong[i] == '/'){
            this->ngaykyhopdong[i] = ' ';
        }
    }

    stringstream ss(this->ngaykyhopdong);
    string word;

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

    this->ngaykyhopdong = newDate;
}

void NV::standardizeName(){
    string newName = "";
    
    stringstream ss(this->hoten);
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
    this->hoten = newName;
}

int main(){
    NV x;
    cin >> x;
    x.setMaNV("00001");
    x.standardizeDate();
    x.standardizeKyHopDong();
    x.standardizeName();
    cout << x;

    return 0;
}