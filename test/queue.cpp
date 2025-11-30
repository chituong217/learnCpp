#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<long long> q;
    q.push(6);
    q.push(8);
    vector <long long> lp;
    while (1){
        long long dinh = q.front(); q.pop();
        lp.push_back(dinh);
        if (lp.size() == 1000){
            break;
        }
        q.push(dinh*10 + 6);
        q.push(dinh*10 + 8);
    }
    for (int i = 0; i < (int)lp.size(); i++){
        cout << lp[i] << endl;
    }
    return 0;
}