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

int main (){
	long long n;
	scanf("%lld", &n);
	long long dem=0;
	for (long long i=1; i<=sqrt(n); i++){
		if (snt(i)){
			dem++;
		}
	}
	printf("%lld", dem);
	return 0;
}
