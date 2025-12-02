#include <stdio.h>
#include <math.h>

long long th(int k, int n){
	long long th=1;
	for (int i=1; i<=k; i++){
		th *=(n-i+1);
		th /= i;
	}
	return th;
}

int main(){
	int k, n;
	scanf("%d %d", &k, &n);
	printf("%lld", th(k,n));
	return 0;
}
