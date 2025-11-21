#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double thuchanh, btlithuyet, thilithuyet;
    bool copy;
    cout << "Nhap vao diem cua 3 cot diem: ";
    cin >> thuchanh >> btlithuyet >> thilithuyet;
    cout << "Sinh vien co copy bai hay khong (1 hoac 0):";
    cin >> copy;
    double tong = thuchanh * 0.3 + btlithuyet * 0.3 + thilithuyet * 0.4;
    if (thuchanh == 0 || btlithuyet == 0 || thilithuyet == 0 || copy == 1 || tong <5){
        cout << "Sinh vien da rot!" << endl;
    }
    else{
        cout << "Sinh vien da dau!" << endl;
    }
    return 0;
}