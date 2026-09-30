#include <bits/stdc++.h>

using namespace std;

struct Point{
    double x, y;
};

void drawALine(Point a, Point b){
    // noi 2 duong thang
}

void veHinhChuNhat(int dai, int rong){
    for (int i = 0; i < rong; i++){
        for (int j = 0; j < dai; j++){
            if (i == 0 || i == rong - 1 || j == 0 || j == dai - 1){
                cout << "*";
            }
            else{
                cout << " ";
            }
        }
        cout << "\n";
    }
}

double tinhChuViHCN(Point a, Point b, Point c, Point d){
    double canhDai = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
    double canhRong = sqrt(pow(b.x - c.x, 2) + pow(b.y - c.y, 2));
    return (canhDai + canhRong) * 2.0;
}

double tinhChuViTamGiac(Point a, Point b, Point c){
    double canh1 = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
    double canh2 = sqrt(pow(b.x - c.x, 2) + pow(b.y - c.y, 2));
    double canh3 = sqrt(pow(a.x - c.x, 2) + pow(a.y - c.y, 2));

    return canh1 + canh2 + canh3;
}

double tinhDienTichHCN(Point a, Point b, Point c, Point d){
    double canhDai = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
    double canhRong = sqrt(pow(b.x - c.x, 2) + pow(b.y - c.y, 2));
    return canhDai * canhRong;
}

double tinhDienTichTamGiac(Point a, Point b, Point c){
    double canh1 = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
    double canh2 = sqrt(pow(b.x - c.x, 2) + pow(b.y - c.y, 2));
    double canh3 = sqrt(pow(a.x - c.x, 2) + pow(a.y - c.y, 2));

    double p = (canh1 + canh2 + canh3)/2.0;
    return sqrt(p * (p - canh1) * (p - canh2) * (p - canh3));
}

int main(){
    veHinhChuNhat(7, 3);

    return 0;
}