#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_N = 100005;
const int MAX_LEN = 105;

char a[MAX_N][MAX_LEN]; 
int pos[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];  // Đọc thẳng vào mảng char
        pos[i] = i;   // Phát bảng tên cho từng đứa: 0, 1, 2, ..., n-1
    }

    // Tung chiêu: Sắp xếp gián tiếp (Indirect Sorting)
    // Chỉ đổi chỗ các con số trong mảng pos, dựa trên nội dung của mảng a
    sort(pos, pos + n, [](int i, int j) {
        // Hàm strcmp trả về giá trị âm nếu chuỗi i nhỏ hơn chuỗi j (theo từ điển)
        return strcmp(a[i], a[j]) < 0; 
    });

    // In output
    cout << n << "\n";
    for (int i = 0; i < n; ++i) {
        // In ra chuỗi dựa theo thứ tự "bảng tên" đã được sắp xếp
        cout << a[pos[i]] << "\n";
    }

    return 0;
}