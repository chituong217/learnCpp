#include <stdio.h>
#include <math.h>
int main(){
	int n;
	long long gt=1;
	scanf("%d", &n);
	for (int i=1; i<=n; i++){
		gt *=i;
	}
	printf("%lld", gt);
	return 0;
}
