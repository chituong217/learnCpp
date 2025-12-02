#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	if (n%2==0){
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	if (n%3==0 && n%5==0){
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	if ( n%3==0 && n%7!=0){
		printf("YES\n");
	} else {
		printf ("NO\n");
	}
	if (n%3==0 || n%7==0){
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	if (n >30 && n<50){
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	if ( n>=30 && (n%2==0 || n%3==0 || n%5==0)){
		printf("YES\n");
	} else {
		printf ("NO\n");
	}
	int tancung = n%10;
	if (n>=10 && n<=99 && (tancung==2 || tancung==3 || tancung==5)){
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	if (n<=100 && n%23==0){
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	if (!(n>=10 && n<=20)){
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	if (tancung % 3 ==0){
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}
