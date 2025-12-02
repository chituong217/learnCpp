#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main(){
	int r;
	cin >> r;
	cout<<fixed<<setprecision(2) <<2*3.14*r <<" "<< 3.14*pow(r,2);
	return 0;
}
