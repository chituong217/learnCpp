#include <stdio.h>
#include <math.h>

int ucln(int a, int b){
	while (b!=0){
		int r= a%b;
		a=b;
		b=r;
	}
	return a;
}

int bcnn (int a, int b){
	return a*b/ucln(a,b);
}

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", bcnn(a,b));
	return 0;
}
