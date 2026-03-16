#include <iostream>

using namespace std;

class Point{
    private: // Data-Values
        float x;
        float y;
        float z;
    public: // Operations-Methods
        Point(){ // Constructor : run when the class is called
            x = 0;
            y = 0;
            z = 0;
        }
        Point(float _x, float _y, float _z){ // we can init many constructors
            x = _x;
            y = _y;
            z = _z;
        }
        void Init(){
            x = 0;
            y = 0;
            z = 0;
        }
        void Print(){
            cout << "X Y Z = " << x << ' ' << y << ' ' << z << endl;
        }
        void SetX(float _x){
            x = _x;
        }

};

int main(){
    // Point is a class
    // Point *p = new Point();
    // p->Print();
    // using as a pointer


    Point p1; // p1 is a object
    Point p2(2,5,3);
    //p.Init();
    p1.Print();
    p2.Print();

    // we usually put variables in private and use methods to change the value
    p2.SetX(999);
    p2.Print();

    return 0;
}