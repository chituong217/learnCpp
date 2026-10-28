#include <bits/stdc++.h>

using namespace std;

class A{
private:
    int dem;
public:
    void display(){
        cout << "Hello fen" << endl;
    }
};

class B : virtual public A{

};

class C : virtual public A{

};

class D : public B, public C{

};

int main(){
    D test;
    test.display();

    return 0;
}