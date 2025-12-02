#include <stdio.h>
#define ll long long

int dif (int a[], int n){
	int dif=0;
	for (int i=0; i<n; i++){
		int kt=0;
		for(int j=0; j<i; j++){
			if (a[i]==a[j]){
				kt++;
				break;
			}
		}
		if (kt<1) dif++;
	}
	return dif;
}

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	printf("%d", dif(a, n));
	return 0;
}
