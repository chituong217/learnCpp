#include <stdio.h>
#define ll long long


int dx(int a[], int n, int i){
	if (n==i && a[i]==a[n-1]) return 1;
	if (i== n-1) return 1;
	if (a[i]==a[n-1]){
		return dx(a, n-1, i+1);
	}
	else return 0;
}

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	int i=0;
	if (dx(a, n, i)==1) printf("YES");
	else printf("NO");
	return 0;
}
