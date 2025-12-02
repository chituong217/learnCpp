#include <stdio.h>
#include <math.h>


int snt(long long n){
	if (n<2) return 0;
	for (long long i=2; i<=sqrt(n); i++){
		if (n%i==0){
			return 0;
		}
	}
	return 1;
}

int tsnt(long long n){
	for (int i=2; i<=sqrt(n); i++){
		while (n%i==0){
			printf("%d ", i);
			n/=i;
		}
	}
	if (snt(n)){
		printf("%lld",n);
	}
}

int main(){
	long long n;
	scanf("%lld", &n);
	tsnt(n);
	
	return 0;
}
