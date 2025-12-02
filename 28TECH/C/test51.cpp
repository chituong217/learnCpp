#include <stdio.h>

int lat(int n){
	int lat=0;
	while (n){
		lat = lat*10 + n%10;
		n/=10;
	}
	return lat;
}

int main(){
	int n;
	scanf("%d", &n);
	printf ("%d", n==lat(n));
	return 0;
}
