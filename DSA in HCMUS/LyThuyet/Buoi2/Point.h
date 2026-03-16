#ifndef _FUNCION_H
#define _FUNCION_H
#include <iostream>

using namespace std;

class Point{
    private: // Data-Values
        float x;
        float y;
        float z;
    public: // Operations-Methods
        Point();
        void Init();
        void Print();
};

#endif