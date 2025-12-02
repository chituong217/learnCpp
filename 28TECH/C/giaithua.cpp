#include <stdio.h>

long long gt (int n){
	long long gt =1;
	for (int i=1; i<=n; i++){
		gt*=i;
	}
	return gt;
} 

int main(){
	int n;
	scanf("%d", &n);
	printf("%lld", gt(n));
	return 0;
}
