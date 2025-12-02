#include <stdio.h>
#include <math.h>

long long shh(long long n){
	long long tong =0;
	for (long long i=1; i<=sqrt(n); i++){
		if (n%i==0){
			tong +=i;
			if (i!=n/i){
				tong+= n/i;
			}
		}
	}
	return tong-n == n;
}

int main(){
	long long n;
	scanf("%lld", &n);
	if (shh(n)==1) printf("YES\n");
	else printf("NO\n");
	return 0;
}
