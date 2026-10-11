// Bai tap 1.2
#include <bits/stdc++.h>

using namespace std;

class DiemKhongGian{
private:
    float x, y, z;
public:
    void Nhap();
    void Xuat();
    float TinhKhoangCach(DiemKhongGian P2);
};

void DiemKhongGian::Nhap(){
    cout << "Moi nhap toa do (x, y, z):";
    cin >> x >> y >> z;
    cout << "\n";
}

void DiemKhongGian::Xuat(){
    cout << "(" << x << ", " << y << ", " << z << ")\n";
}

float DiemKhongGian::TinhKhoangCach(const DiemKhongGian &P2){
    return sqrt(pow(this->x - P2.x, 2) + pow(this->y - P2.y, 2) + pow(this->z - P2.z, 2));
}

int main(){



    return 0;
}