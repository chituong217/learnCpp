#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char id[9]; // do co 1 '\0' ở cuối nên phải thêm 1 kí tự vào chuỗi 8->9
    char name[101];
    // cin >> name; chỉ nhận chuỗi ko khoảng trắng
    cin.get(name, 101, '\n'); // đọc đến khi đủ 100 kí tự hoặc khi nào gặp '\n' thì dừng
    cout << "Name : " << name << endl;
    cout << "Length : " << strlen(name) << endl;
    return 0;
}