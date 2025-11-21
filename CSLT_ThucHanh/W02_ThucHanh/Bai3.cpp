#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double thuchanh, btlithuyet, thilithuyet;
    cout << "Nhap vao diem cua 3 cot diem: ";
    cin >> thuchanh >> btlithuyet >> thilithuyet;
    double tong = thuchanh * 0.3 + btlithuyet * 0.3 + thilithuyet * 0.4;
    if (tong <5){
        cout << "Sinh vien da rot!" << endl;
    }
    else{
        cout << "Sinh vien da dau!" << endl;
    }
    return 0;
}