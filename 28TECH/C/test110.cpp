#include <stdio.h>
#define ll long long

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	int min= a[0];
	int cnt=0;
	for (int i=0; i<n; i++){
		if (min == a[i]) cnt++;
		if (min > a[i]){
			min =a[i];
			cnt=1;
		}
	}
	printf("%d", cnt);
}
