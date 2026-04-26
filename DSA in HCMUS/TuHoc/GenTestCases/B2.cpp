// Ép xung CPU tối đa
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <vector>
#include <string_view>
#include <algorithm>
#include <cstdio>

using namespace std;

// Tạo một bộ đệm siêu to khổng lồ 11MB (Lưu ở vùng nhớ tĩnh BSS, không lo tràn Stack)
// N max = 100,000; Len max = 100 -> Max = 10,000,000 ký tự + 100,000 dấu \n
const int MAX_BUF = 11000000; 
char in_buf[MAX_BUF];

int main() {
    // Đọc con số n đầu tiên bằng scanf cho lẹ
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    // Xóa hết các dấu xuống dòng, khoảng trắng dư thừa sau con số n
    int c;
    while ((c = getchar()) != EOF && c <= ' ');

    // Đặt lại con trỏ ký tự đầu tiên của chuỗi
    ungetc(c, stdin);

    // [CHIÊU CUỐI I/O] Hút toàn bộ phần còn lại của file vào in_buf trong 1 nốt nhạc
    size_t bytes_read = fread(in_buf, 1, MAX_BUF, stdin);
    in_buf[bytes_read] = '\0'; // Chốt sổ mảng

    // Dùng vector chứa "Kính lúp" string_view
    vector<string_view> a;
    a.reserve(n); // Cấp phát chỗ trước để vector không bị lag

    // Dùng 1 con trỏ quét qua cái mảng khổng lồ để cắt từ
    char* ptr = in_buf;
    while (*ptr != '\0') {
        // Bỏ qua các ký tự rác (xuống dòng, khoảng trắng)
        while (*ptr == '\n' || *ptr == '\r' || *ptr == ' ') ptr++;
        if (*ptr == '\0') break;
        
        char* start = ptr; // Đánh dấu đầu chuỗi
        
        // Chạy tới khi đụng dấu xuống dòng thì dừng -> Tìm được đuôi chuỗi
        while (*ptr != '\n' && *ptr != '\r' && *ptr != ' ' && *ptr != '\0') ptr++;
        
        // Tạo kính lúp soi vào đúng khoảng start -> ptr
        a.emplace_back(start, ptr - start);
    }

    // Tung std::sort để sắp xếp các kính lúp. 
    // Tốc độ ánh sáng vì không có phép copy chuỗi nào diễn ra!
    sort(a.begin(), a.end());

    // In output bằng printf cực nhanh
    printf("%d\n", n);
    for (int i = 0; i < a.size(); ++i) {
        // string_view không có sẵn ký tự '\0' ở cuối nên phải in bằng fwrite hoặc chỉ định độ dài
        fwrite(a[i].data(), 1, a[i].length(), stdout);
        putchar('\n');
    }

    return 0;
}