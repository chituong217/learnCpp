
#include <iostream>
#include <stdexcept>
using namespace std;

class ScoreList {
private:
    int scores[3];

public:
    ScoreList() {
        scores[0] = 7;
        scores[1] = 8;
        scores[2] = 9;
    }

    // TODO: Viet operator[]
    int& operator [] (int index){
        if (index < 0 || index >= 3) {
            throw out_of_range("Chi so nam ngoai pham vi!");
        }
        else {
            return scores[index];
        }
    }
};

int main() {
    ScoreList s;

    cout << s[0] << endl;

    s[1] = 10;

    cout << s[1] << endl;

    return 0;
}
