#include <bits/stdc++.h>

using namespace std;

long long ucln(long long a, long long b){
    while (b != 0){
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

class ps{
private:
    long long ts, ms;
public:
    void rutGonPhanSo();
    friend istream& operator >> (istream &in, ps &x){
        in >> x.ts >> x.ms;
        return in;
    }

    friend ostream& operator << (ostream &out, ps x){
        if (x.ms == 0){
            out << "Phan so vo dinh" << endl;
        }
        else if (x.ts == 0){
            out << "0" << endl;
        }
        else{
            out << x.ts << "/" << x.ms << endl;
        }
        return out;
    }
};

void ps::rutGonPhanSo(){
    if (ts == 0 || ms == 0) return;

    long long u = ucln(ts, ms);
    ts /= u;
    ms /= u;
}

int main(){
    ps x;
    cin >> x;
    x.rutGonPhanSo();
    cout << x;

    return 0;
}