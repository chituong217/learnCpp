#include <stdio.h>
#include <math.h>

long long th(int k, int n){
	k = fmin(k, n-k);
	long long tich =1;
	for (int i=1; i<=k; i++){
		tich *= (n-i+1);
		tich/=i;
	}
	return tich;
}


long long pascal (int cc){
	for (int i=0; i<cc; i++){
		for (int j=0; j<=i; j++){
			printf("%lld ", th(j,i));
		}
		printf("\n");
	}
}
int main(){
	int cc;
	scanf("%d", &cc);
	pascal(cc);
	return 0;
}
