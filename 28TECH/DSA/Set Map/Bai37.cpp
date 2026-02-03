#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main(){
    map<string, vector<pair<int, int> > > mp;
    string line;
    while (getline(cin, line)){
        string ten;
        string tinchiS;
        string diemsoS;

        stringstream ss(line);
        ss >> ten;
        ss >> tinchiS;
        ss >> diemsoS;

        int tinchi = stoi(tinchiS);
        int diemso = stoi(diemsoS);

        pair<int, int> tmp;
        tmp.first = tinchi;
        tmp.second = diemso;

        mp[ten].push_back(tmp);
    }

    for (auto it = mp.rbegin(); it != mp.rend(); it++){
        cout << it->first << " : ";

        double gpa = 0;
        int tongtinchi = 0;
        for (auto it1 = it->second.begin(); it1 != it->second.end(); it1++){
            gpa += (it1->first * it1->second);
            tongtinchi += it1->first;
        }
        gpa /= (double)tongtinchi;
        cout << fixed << setprecision(2) << gpa << endl;
    }

    return 0;
}