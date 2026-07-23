#include <bits/stdc++.h>

using namespace std;

class Rectangle{
private:
    double width, height;
    string color;
public:
    Rectangle(){
        
    }
    Rectangle(double width, double height, string color){
        this->width = width;
        this->height = height;
        this->color = color;
    } 

    friend istream& operator >> (istream &in, Rectangle &x){
        in >> x.width >> x.height >> x.color;
        return in;
    }

    friend ostream& operator << (ostream &out, Rectangle x){
        if (x.width > 0 && x.height > 0){
            out << x.findPerimeter() << ' ' << x.findArea() << ' ' << x.color << endl;
        }
        else{
            out << "INVALID" << endl;
        }

        return out;
    }

    double getWidth();
    void setWidth(double width);
    double getHeight();
    void setHeight(double height);
    string getColor();
    void setColor(string color);
    double findArea();
    double findPerimeter();
    void standardizeColorName();
};

double Rectangle::getWidth(){
    return this->width;
}

void Rectangle::setWidth(double width){
    this->width = width;
}

double Rectangle::getHeight(){
    return this->height;
}

void Rectangle::setHeight(double height){
    this->height = height;
}

string Rectangle::getColor(){
    return this->color;
}

void Rectangle::setColor(string color){
    this->color = color;
}

double Rectangle::findArea(){
    return (height * width);
}

double Rectangle::findPerimeter(){
    return 2.0 * (height + width);
}

void Rectangle::standardizeColorName(){
    for (int i = 0; i < (int)color.size(); i++){
        if (i == 0) color[i] = toupper(color[i]);
        else color[i] = tolower(color[i]);
    }
}

int main(){
    Rectangle x;
    cin >> x;
    x.standardizeColorName();
    cout << x;

    return 0;
}