#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	int dem[3]={0};
	for (int i=0; i<n; i++){
		dem[a[i]]++;
	}
	for (int i=0; i<=2; i++){
		while (dem[i]>0){
			printf("%d ", i);
			dem[i]--;
		}
	}
	return 0;
}
