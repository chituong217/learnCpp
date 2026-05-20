#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
bool taken[1000005]; // false la trong tap V, true la trong tap MST
vector<pair<int,int>> adj[1000005]; // canh ke voi first la dinh second la trong so

void nhap(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;

        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
}

void Prim(int s){
    taken[s] = true; // nap s vao cay khung MST
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
    // dung priority queue luu cac pair, first la trong so second la dinh
    // min heap de cho trong so nho nhat len dau
    for (auto it : adj[s]){ // duyet danh sach ke cua dinh s
        int t = it.first; // dinh ke cua s
        if (taken[t] == false){ // neu chua nam trong MST
            Q.push({it.second, t}); // them vao hang doi uu tien 
        }
    }

    long long d = 0, dem = 0;
    while (Q.empty() == false){
        // LAY RA CANH NGAN NHAT
        pair<int, int> e = Q.top(); Q.pop();
        int u = e.second, w = e.first;

        if (taken[u] == false){ // QUAN TRONG : Can kiem tra truoc khi dua vao MST
            // check xem u con nam trong V ko
            dem++;
            d += w;
            taken[u] = true; // da nap u vao trong MST
            for (auto it : adj[u]){ // duyet danh sach ke cua u de them vao Priority Queue
                if (taken[it.first] == false){
                    Q.push({it.second, it.first});
                }
            }
        }
    }

    if (dem == n - 1){
        cout << d << endl; // ton tai cay khung cuc tieu
    }
    else{
        cout << "IMPOSSIBLE\n";
    }
}

int main(){
    nhap();
    Prim(1);

    return 0;
}