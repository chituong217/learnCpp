#include <bits/stdc++.h>

using namespace std;

class SafeArray{
private:
    int* data;
    int size;
public:
    SafeArray();
    SafeArray(int n);
    ~SafeArray();
    int& operator[] (int index);
    const int& operator[] (int index) const;
    operator bool() const;
};

SafeArray::SafeArray(){
    data = nullptr;
    size = 0;
}

SafeArray::SafeArray(int n){
    if (n <= 0){
        data = nullptr;
        size = 0;
    }
    else{
        size = n;
        data = new int[size];
        for (int i = 0; i < n; i++){
            data[i] = 0;
        }
    }
}

SafeArray::~SafeArray(){
    if (data != nullptr){
        delete []data;
    }
    size = 0;
    data = nullptr;
}

int& SafeArray::operator[] (int index){
    if (index < 0 || index >= size){
        cout << "Loi: Chi so vuot qua pham vi mang!\n"; 
        return data[0];
    }
    else{
        return data[index];
    }
}

const int& SafeArray::operator[] (int index) const{
    if (index < 0 || index >= size){
        cout << "Loi: Chi so vuot qua pham vi mang!\n"; 
        return data[0];
    }
    else{
        return data[index];
    }
}

SafeArray::operator bool() const{
    if (size > 0 && data != nullptr) return true;
    return false;
}

int main(){

    return 0;
}