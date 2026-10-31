#include <bits/stdc++.h>

using namespace std;

class DaThuc {
private:
    long long a[101];
    int n;
public:
    DaThuc(){
        for (int i = 0; i < 101; i++){
            a[i] = 0;
        }
    }
    DaThuc(int n, const int a[]){
        for (int i = 0; i <= n; i++){
            this->a[i] = a[i];
        }
        for (int i = n + 1; i < 101; i++){
            this->a[i] = 0;
        }
    }
    int bac() const{
        for (int i = 100; i >= 0; i--){
            if (a[i] != 0){
                return i;
            }
        }
        return -1;
    }
    int operator[](int i) const{
        if (i < 0 || i > 100) return 0;
        if (i > bac()) return 0;
        return a[i];
    }

    DaThuc operator+(const DaThuc& b) const{
        DaThuc moi;
        for (int i = 0; i < 101; i++){
            moi.a[i] = this->a[i] + b.a[i];
        }
        return moi;
    }
    DaThuc operator-(const DaThuc& b) const{
        DaThuc moi;
        for (int i = 0; i < 101; i++){
            moi.a[i] = this->a[i] - b.a[i];
        }
        return moi;
    }
    DaThuc operator*(const DaThuc& b) const{
        DaThuc moi;
        for (int k = 0; k < 101; k++){
            long long sum = 0;
            for (int i = 0; i <= k; i++){
                sum += this->a[i] * b.a[k - i];
            }
            moi.a[k] = sum;
        }
        return moi;
    }
    long long giaTri(int x) const{
        long long ans = 0;
        for (int i = 0; i < 101; i++){
            ans += (long long)(pow(x, i) * this->a[i]);
        }
        return ans;
    }
    friend std::ostream& operator<<(std::ostream& os, const DaThuc& p){
        bool isFirst = true;
        for (int i = 100; i >= 0; i--){
            if (p.a[i] == 0) continue;
            
            if (isFirst){
                if (p.a[i] < 0) os << "-";
                isFirst = false;
            }
            else{
                if (p.a[i] < 0) os << " - ";
                else os << " + ";
            }

            int tritd = abs(p.a[i]);
            if (i == 0 || tritd != 1){
                os << tritd;
            }
            if (i > 0){
                os << "x";
            }
            if (i >= 2){
                os << "^" << i;
            }
        }

        if (isFirst == true) os << "0";
        return os;
    }
};


int main(){
    return 0;
}