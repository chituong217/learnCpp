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

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", ucln(a,b));
	return 0;
}
