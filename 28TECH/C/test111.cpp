#include <stdio.h>
#define ll long long

int main(){
	int n, x;
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	scanf("%d", &x);
	int lon=0, be=0;
	for (int i=0; i<n; i++){
		if (a[i]>x) lon++;
		else if (a[i]<x) be++;
	}
	printf("%d\n", be);
	printf("%d", lon);
	return 0;
}
