#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	int found =0;
	for (int i=1; i<n; i++){
		for (int j=0; j<i; j++){
		if (a[i]==a[j]) {
			found++;
			printf("%d", a[i]);
			break;
		}	
		}
		if (found >0) break;
	}
	if (found==0) printf("-1");
	return 0;
}
