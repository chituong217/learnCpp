#include <iostream>
#include "Point.h"

using namespace std;

Point::Point(){
    x = 0;
    y = 0;
    z = 0;
}

void Point::Init(){
    x = 0;
    y = 0;
    z = 0;
}

void Point::Print(){
    cout << "X Y Z = " << x << ' ' << y << ' ' << z << endl;
}


int main(){
    Point x;
    x.Print();
    return 0;
}

