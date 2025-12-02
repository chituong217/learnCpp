#include <stdio.h>
#include <algorithm>
int main (){
	long long a, b;
	scanf("%lld %lld", &a, &b);
	long long min = std::min({a,b});
	printf("%lld", min*(min-1));
}
