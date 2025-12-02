#include <stdio.h>
#include <math.h>

int ucln(int a, int b){
	if (b==0) return a;
	else return ucln(b, a%b);
}

int csntcn(int a[], int n){
	int cnt=0;
	for (int i=0; i<n-1; i++){
		for (int j = i+1; j<n; j++){
			if (ucln(a[i], a[j])==1){
				cnt++;
			}
		}
	}
	return cnt;
}

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	printf("%d", csntcn(a, n));
	return 0;
}
