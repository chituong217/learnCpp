#include <stdio.h>

int is_sorted(int a[], int n, int i){
	if (i == n) return 1;
	if (a[i] <= a[i-1]) return 0;
	else return is_sorted(a, n, ++i);
}


int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	if (is_sorted(a, n, 1)) printf("YES");
	else printf("NO");
	return 0;
}
