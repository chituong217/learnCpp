#include <stdio.h>

int check(int a[], int n){
	int b[100];
	b[25]=0; b[50]=0; b[100]=0;
	for (int i=0; i<n; i++){
		if (a[i]==25){
			b[25]++;
		}
		else if (a[i]==50){
			--b[25];
			if (b[25]<0) return 0;
			++ b[50];
		}
		else if (a[i]==100){
			if (b[50]==0){
				b[25]-=3;
				if (b[25]<0) return 0;
				++b[100];
			}
			else {
				--b[25];
				--b[50];
				if (b[25]<0) return 0;
				++b[100];
			}
		}
	}
	return 1;
}


int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	if (check(a, n)) printf("YES");
	else printf("NO");
	return 0;
}
