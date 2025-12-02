#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
int main(){
	int x,y,z,t;
	scanf("%d %d %d %d", &x, &y, &z, &t);
	printf("%d\n", (int)fmax(x,y));
	printf("%d\n", (int)fmin (z,t));
	printf("%d\n", (int)max({x,y,z}));
	printf("%d\n", (int)min({x,y,z,t}));
	return 0;
}
