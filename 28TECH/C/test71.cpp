#include <stdio.h>
#include <math.h>

int snt(long long n){
	for (long long i=2; i<=sqrt(n); i++){
		if (n%i==0) return 0;
	}
	return 1;
}

int shh (long long n){
	for (long long i=1; i<=32; i++){
		if ( snt(i)==1 && snt( pow(2,i) -1 )){
			if ((pow(2, (i-1)) * (pow(2,i)-1)) ==n) return 1;
		}
	}
	return 0;
}

int main(){
	long long n;
	scanf("%lld", &n);
	if (shh(n)==1) printf("YES\n");
	else printf("NO\n");
	return 0;
}
