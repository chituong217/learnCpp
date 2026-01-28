#include <iostream>
using namespace std;

int main(){
    char c;
    int a, b;
    cout << "Enter two integers =";
    cin >> a >> b;
    cin.ignore();
    cout << "Enter an opertor (+, -, *, /, %) =";
    cin >> c;
    if ( c == '+'){
        cout << "Result = " << a+b << endl;
    }
    else if (c == '-'){
        cout << "Result = " << a-b << endl;
    }
    else if (c == '*'){
        cout << "Result = " << a*b << endl;
    }
    else if (c == '/'){
        if (b == 0){
            cout << "Error: divided by zero." << endl;
        }
        else{
            cout << "Result = " << a/b << endl;
        }
    }
    else if (c == '%'){
        if (b == 0){
            cout << "Error: divided by zero." << endl;
        }
        else{
            cout << "Result = " << a%b << endl;
        }
    }
    return 0;
}