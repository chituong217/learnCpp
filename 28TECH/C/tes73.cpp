#include <stdio.h>

int stn(int n){
	int lat=0;
	int res=n;
	while (n){
		lat = lat*10 +n%10;
		n/=10;
	}
	return lat==res;
}

int least(int n){
	while (n){
		if (n%10==6) return 1;
		n/=10;
	}
	return 0;
}

int tong(int n){
	int tong =0;
	while (n){
		tong+= n%10;
		n/=10;
	}
	return (tong%10)==8;
}

int slp(int n){
	return ((stn(n)==1) && (least(n)==1) && (tong(n)==1));
}

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	for (int i=a; i<=b; i++){
		if (slp(i)==1) printf("%d ", i);
	}
	return 0;
}
