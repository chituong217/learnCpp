#include <bits/stdc++.h>

using namespace std;

class sv{
private:
    string masv, hoten, lop, email;
public:
    void standardizeName();

    friend istream& operator >> (istream &in, sv &x){
        getline(in, x.masv);
        getline(in, x.hoten);
        getline(in, x.lop);
        getline(in, x.email);

        x.standardizeName();

        return in;
    }

    friend ostream& operator << (ostream &out, sv x){
        out << x.masv << ' ' << x.hoten << ' ' << x.lop << ' ' << x.email;

        return out;
    }

    string getNam();
};

void sv::standardizeName(){
    string res = "";
    string name = hoten;

    stringstream ss(name);
    string word;

    while (ss >> word){
        for (int i = 0; i < (int)word.size(); i++){
            if (i == 0) word[i] = toupper(word[i]);
            else word[i] = tolower(word[i]);
        }
        res += word;
        res += " ";
    }
    res.pop_back();

    this->hoten = res;
}

string sv::getNam(){
    return masv.substr(0, 4);
}

int main(){
    int n;
    cin >> n;
    cin >> ws;

    vector<sv> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    int q;
    cin >> q;

    while (q--){
        string nam;
        cin >> nam;

        cout << "DANH SACH SINH VIEN KHOA " << nam << " :\n";
        for (int i = 0; i < n; i++){
            if (nam == v[i].getNam()){
                cout << v[i] << endl;
            }
        }
    }

    return 0;
}
