#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // Lập sẵn 101 cái rổ (Bucket)
    // bucket[10] sẽ chứa tất cả các chuỗi có độ dài bằng 10
    vector<string> buckets[101];

    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        // Phân lô bán nền: Dài bao nhiêu quăng vào rổ bấy nhiêu
        buckets[s.length()].push_back(s);
    }

    cout << n << "\n";
    
    // Quét từ rổ số 10 đến rổ 100 (vì đề cho độ dài tối thiểu là 10, tối đa 100)
    for (int len = 10; len <= 100; ++len) {
        // Rổ nào có đồ mới xử lý
        if (!buckets[len].empty()) {
            // Sort các chuỗi TRONG CÙNG 1 RỔ theo thứ tự từ điển
            sort(buckets[len].begin(), buckets[len].end());
            
            // In thẳng ra luôn
            for (const string& str : buckets[len]) {
                cout << str << "\n";
            }
        }
    }

    return 0;
}