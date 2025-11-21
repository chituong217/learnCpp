#include <iostream>
#include <cstdio>
using namespace std;

int main (){
  char buffer[100];
  int myInt = 2025;
  float myFloat = 3.14159;
  sprintf(buffer, "Gia tri so nguyen: %d", myInt);
  cout << "Chuoi 1: " << buffer << endl;

  sprintf(buffer, "Gia tri so thuc: %.2f", myFloat);
  cout << "Chuoi 2: " << buffer << endl;

  sprintf(buffer, "Int: %d, Float: %.2f", myInt, myFloat);
  cout << "Chuoi 3: " << buffer << endl;

  return 0;
}