#include <bits/stdc++.h>

using namespace std;

class SoTien {
private:
    long long money;
public:
    SoTien(){
        money = 0;
    }
    SoTien(long long dong, long long xu){
        money = dong * 100 + xu;
    }

    long long getDong() const{
        return money/100;
    }
    long long getXu() const{
        return money%100;
    }

    SoTien operator+(const SoTien& khac) const{
        SoTien moi;
        moi.money = this->money + khac.money;
        return moi;
    }
    SoTien operator-(const SoTien& khac) const{
        SoTien moi;
        moi.money = this->money - khac.money;
        return moi;
    }

    SoTien& operator+=(const SoTien& khac){
        this->money += khac.money;
        return *this;
    }
    SoTien& operator-=(const SoTien& khac){
        this->money -= khac.money;
        return *this;
    }

    bool operator==(const SoTien& khac) const{
        if (this->money == khac.money) return true;
        return false;
    }
    bool operator!=(const SoTien& khac) const{
        return !(*this == khac);
    }
    bool operator<(const SoTien& khac) const{
        return this->money < khac.money;
    }
    bool operator<=(const SoTien& khac) const{
        return this->money <= khac.money;
    }
    bool operator>(const SoTien& khac) const{
        return this->money > khac.money;
    }
    bool operator>=(const SoTien& khac) const{
        return this->money >= khac.money;
    }

    friend std::ostream& operator<<(std::ostream& os, const SoTien& st){
        os << st.money/100 << " dong " << st.money%100 << " xu";
        return os;
    }
};


int main(){
    return 0;
}