#include <bits/stdc++.h>

using namespace std;

class SoTien {
private:
    long long dong, xu;
public:
    SoTien(){
        dong = 0;
        xu = 0;
    }                                  
    SoTien(long long dong, long long xu){
        this->xu = xu;
        this->dong = dong;
        this->normalize();
    }

    long long getDong() const{
        return dong;
    }
    long long getXu() const{
        return xu;
    }
    void normalize(){
        long long tong = dong * 100 + xu;
        dong = tong / 100;
        xu = tong % 100;
    }

    SoTien operator+(const SoTien& khac) const{
        SoTien moi;
        moi.dong = this->dong + khac.dong;
        moi.xu = this->xu + khac.xu;
        moi.normalize();
        return moi;
    }
    SoTien operator-(const SoTien& khac) const{
        SoTien moi;
        moi.dong = this->dong - khac.dong;
        moi.xu = this->xu - khac.xu;
        moi.normalize();
        return moi;
    }

    SoTien& operator+=(const SoTien& khac){
        this->dong += khac.dong;
        this->xu += khac.xu;
        this->normalize();
        return *this;
    }
    SoTien& operator-=(const SoTien& khac){
        this->dong -= khac.dong;
        this->xu -= khac.xu;
        this->normalize();
        return *this;
    }

    bool operator==(const SoTien& khac) const{
        if (this->xu == khac.xu && this->dong == khac.dong){
            return true;
        }
        return false;
    }
    bool operator!=(const SoTien& khac) const{
        if (*this == khac) return false;
        return true;
    }
    bool operator<(const SoTien& khac) const{
        if (this->dong < khac.dong) return true;
        else if (this->dong == khac.dong){
            return this->xu < khac.xu;
        }
        return false;
    }
    bool operator<=(const SoTien& khac){
        if (this->dong < khac.dong) return true;
        else if (this->dong == khac.dong){
            return this->xu <= khac.xu;
        }
        return false;
    }
    bool operator>(const SoTien& khac) const{
        if (this->dong > khac.dong) return true;
        else if (this->dong == khac.dong){
            return this->xu > khac.xu;
        }
        return false;
    }
    bool operator>=(const SoTien& khac) const{
        if (this->dong > khac.dong) return true;
        else if (this->dong == khac.dong){
            return this->xu >= khac.xu;
        }
        return false;
    }

    friend std::ostream& operator<<(std::ostream& os, const SoTien& st){
        os << st.dong << " dong " << st.xu << " xu";
        return os;
    }
};


int main(){
    return 0;
}