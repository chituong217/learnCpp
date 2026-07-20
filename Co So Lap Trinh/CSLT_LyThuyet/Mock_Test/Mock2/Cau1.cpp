#include <iostream>

using namespace std;

void drawHollowRectangle(int height, int width){
    for (int i = 1; i <= height; i++){
        for (int j = 1; j <= width; j++){
            if (i == 1 || i == height || j == 1 || j == width){
                cout << "*";
            }
            else{
                cout << " ";
            }
        }
        cout << endl;
    }
}