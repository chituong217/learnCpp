#include <stdio.h>
int main(){
	int n;
	long long tong=0;
	int so;
	scanf("%d", &n);
	for (int i=1; i<=n; i++){
		scanf("%d", &so);
		if (so%2==0){
			tong += so;
		}
	}
	printf("%lld", tong);
	return 0;
}
