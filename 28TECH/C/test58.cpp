#include <stdio.h>
#include <math.h>

int snt(int n){
	if (n<2) return 0;
	for (int i=2; i<=sqrt(n); i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}


int tong(int n){
	int gan =n;
	while (n){
		if (snt(n%10)==0) return 0;
		n/=10;
	}
	long long tong =0;
	while (gan){
		tong += gan%10;
		gan/=10;
	}
	return snt(tong);
}

int tnt(int n){
	return (snt(n) && tong(n) );
}

int main(){
	int a, b;
	long long dem=0;
	scanf("%d %d", &a, &b);
	for (int i=a; i<=b; i++){
		if (tnt(i)) {
			dem++;
		}
	}
	printf("%lld", dem);
	return 0;
}
