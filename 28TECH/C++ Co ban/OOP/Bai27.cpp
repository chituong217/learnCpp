#include <bits/stdc++.h>

using namespace std;

long long countTime(string timeIn, string timeOut){
    long long start = (stoll(timeIn.substr(0, 2)) * 60) + stoll(timeIn.substr(3, 2));
    long long end = (stoll(timeOut.substr(0, 2)) * 60) + stoll(timeOut.substr(3, 2));

    return end - start;
}

class player{
private:
    string username, password, name;
    string timeIn, timeOut;
    long long time;
public:
    friend istream& operator >> (istream &in, player &x){
        getline(in, x.username);
        getline(in, x.password);
        getline(in, x.name);
        getline(in, x.timeIn);
        getline(in, x.timeOut);

        x.time = countTime(x.timeIn, x.timeOut);

        return in;
    }

    friend ostream& operator << (ostream &out, player x){
        out << x.username << ' ' << x.password << " " << x.name << " ";

        int gio = (x.time) / 60;
        int phut = (x.time) % 60;

        out << gio << " gio " << phut << " phut";
        return out;
    }

    bool operator < (player khac){
        if (this->time > khac.time) return true;
        else if (this->time < khac.time) return false;
        else{
            return this->username < khac.username;
        }
    }
};

int main(){
    int n;
    cin >> n;
    cin >> ws;

    vector<player> v(n);

    for (int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++){
        cout << v[i] << endl;
    }

    return 0;
}