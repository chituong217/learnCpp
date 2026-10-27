#include <bits/stdc++.h>

using namespace std;

class Money{
private:
    int amount;
    string currency;
public: 
    Money(){
        amount = 0;
        currency = "";
    }
    Money(int sl, string tt) : amount(sl), currency(tt){

    }

    friend Money operator + (const Money &a, const Money &b);

    friend ostream& operator << (ostream &out, const Money &x){
        out << x.amount << ' ' << x.currency;
        return out;
    }
};

Money operator + (const Money &a, const Money &b){
    if (a.currency == b.currency){
        Money moi;
        moi.amount = a.amount + b.amount;
        moi.currency = a.currency;
        return moi;
    }
    else{
        throw invalid_argument("Khong cung currency");
    }
}

int main() {
    Money a(100, "USD");
    Money b(50, "USD");
    Money c(200, "VND");

    cout << a + b << endl;

    try {
        cout << a + c << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Loi: " << e.what() << endl;
    }

    return 0;
}