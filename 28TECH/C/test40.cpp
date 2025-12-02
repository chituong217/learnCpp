#include <stdio.h>
#include <algorithm>
int main(){
	long long a,b;
	scanf("%lld %lld", &a, &b);
	long long min = std::min(a,b);
	long long tich =1;
	for (int i=1; i<=min; i++){
		tich *=i;
	}
	printf("%lld", tich);
}
