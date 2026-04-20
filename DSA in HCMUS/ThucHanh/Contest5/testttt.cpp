#include <iostream>
#include <vector>

using namespace std;

struct leaves{
    string species;
    string color;
};

int main(){
    int n;
    cin >> n;

    vector<leaves> v;
    for (int i = 0; i < n; i++){
        string species, color;
        cin >> species >> color;

        bool isExisted = false;
        for (int j = 0; j < (int)v.size(); j++){
            if (v[j].species == species && v[j].color == color){
                isExisted = true;
            }
        }

        if (isExisted == false){
            leaves tmp;
            tmp.species = species; tmp.color = color;
            v.push_back(tmp);
        }
    }

    cout << v.size();

    return 0;
}