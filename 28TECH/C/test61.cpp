#include <stdio.h>
#include <math.h>

void tsnt(long long n){
	int first =1;
	for (long long i=2; i<= sqrt(n); i++){
		if (n%i==0){
			if (!first) printf(" * ");
			n/=i;
			int mu=1;
			while (n%i==0){
				mu++;
				n/=i;
			}
			printf("%lld^%d", i, mu);
			first =0;
		}
	}
	if (n>2) {
		if (!first) printf(" * ");
		printf("%lld^1", n);
	}
}

int main(){
	long long n;
	scanf("%lld", &n);
	tsnt(n);
	return 0;
}
