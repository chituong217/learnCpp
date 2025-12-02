#include <stdio.h>

int stn(int n){
	int lat =0;
	int tmp =n;
	while (n){
		lat = lat*10 + n%10;
		n/=10;
	}
	return tmp == lat;
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%d", stn(n));
	return 0;
}
