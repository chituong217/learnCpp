#include <iostream>
using namespace std;

int giaiPTBacNhat(float a, float b, float &nghiem) {
    if (a == 0) {
        if (b == 0) {
            return 0; // Vô số nghiệm
        } else {
            return -1; // Vô nghiệm
        }
    } else {
        nghiem = -b / a;
        return 1; // Có 1 nghiệm
    }
}

int main() {
    float x;
    int trangThai = giaiPTBacNhat(2, -4, x); // Truyền x vào để hàm cập nhật giá trị

    if (trangThai == 1) {
        cout << "Phuong trinh co 1 nghiem: x = " << x << endl;// x đã được cập nhật
    }
    else if (trangThai == 0){
        cout << "Phuong trinh co vo so nghiem" << endl;
    }
    else{
        cout << "Phuong trinh vo nghiem" << endl;
    }
    
    return 0;
}