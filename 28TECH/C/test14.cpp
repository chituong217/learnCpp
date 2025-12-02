#include <stdio.h>
int main (){
	int X, Y, Z, T;
	scanf ("%d %d %d %d", &X, &Y, &Z, &T);
	printf ("%d,%d,%d,%d\n", Y, Z, X, T);
	printf ("%lld\n", 1ll*X+Y+Z+T);
	printf ("%lld\n", (1ll*X-Y) + (1ll*Z*T));
	
}
