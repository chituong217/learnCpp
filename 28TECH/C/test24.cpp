#include <stdio.h>
int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if (a==b && b==c && a>0 && b>0 && c>0){
		printf("1");
	}
	else if (((a==b && b!=c ) || (a==c && b!=c) || (b==c && a!=c)) && a>0 && b>0 && c>0) {
		printf("2");
	}
	else if (((a*a + b*b == c*c) || (a*a +c*c == b*b) || (b*b + c*c == a*a)) && a>0 && b>0 && c>0){
		printf("3");
	}
	else if ((a>0 && b>0 && c>0) && a+b>c && a+c>b && b+c>a){
		printf("4");
	}
	else {
		printf("INVALID");
	}
	return 0;
}
