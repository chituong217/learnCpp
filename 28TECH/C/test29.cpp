#include <stdio.h>
#include <math.h>
int main(){
	long long n;
	scanf("%lld", &n);
	long long tong =0;
	for (long long i=1; i<=sqrt(n); i++){
		if (n%i==0){
			tong +=i;
			if ((n/i)!=i){
				tong +=(n/i);
			}
		}
	}
	printf("%lld", tong);
	return 0;
}
