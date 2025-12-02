#include <stdio.h>
#include <math.h>

int ucln(int a, int b){
	if (a==0 || b==0) return a+b;
	while(a!=b){
		if (a>b){
			a-=b;
		}
		else b-=a;
	}
	return a;
}

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", ucln(a,b));
}
