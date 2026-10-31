#include <bits/stdc++.h>

using namespace std;

class Vector2D {
private:
    int x, y;

public:
    Vector2D(){
        x = 0;
        y = 0;
    }                                     
    Vector2D(int x, int y){
        this->x = x;
        this->y = y;
    }

    int getX() const{
        return x;
    }
    int getY() const{
        return y;
    }

    Vector2D operator+(const Vector2D& v) const{
        Vector2D moi;
        moi.x = this->x + v.x;
        moi.y = this->y + v.y;
        return moi;
    }
    Vector2D operator-(const Vector2D& v) const{
        Vector2D moi;
        moi.x = this->x - v.x;
        moi.y = this->y - v.y;
        return moi;
    }
    Vector2D operator-() const{
        Vector2D moi;
        moi.x = -this->x;
        moi.y = -this->y;
        return moi;
    }
    Vector2D operator*(int k) const{
        Vector2D moi;
        moi.x = this->x * k;
        moi.y = this->y * k;
        return moi;
    }

    bool operator==(const Vector2D& v) const{
        if (this->x == v.x && this->y == v.y){
            return true;
        }
        return false;
    }
    bool operator!=(const Vector2D& v) const{
        if (*this == v) return false;
        return true;
    }

    friend Vector2D operator*(int k, const Vector2D& v){
        return v * k;
    }
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& v){
        os << '(' << v.x << ", " << v.y << ")";
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Vector2D& v){
        is >> v.x >> v.y;
        return is;
    }
};


int main(){
    return 0;
}