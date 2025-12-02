#include <stdio.h>

void ts(int a[], int n){
	for (int i=0; i<n; i++){
		int stop=0;
		for(int j=0; j<=i-1; j++){
			if (a[i]==a[j]) stop++;
		}
		int ts=1;
		for(int j= i+1; j<n; j++){
			if (a[i]==a[j]) ts++;
		}
		if (stop>=1) continue;
		printf("%d %d\n", a[i], ts);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	ts(a,n);
	return 0;
}
