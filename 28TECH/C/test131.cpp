#include <stdio.h>
#define ll long long

int main(){
	int n=0, a[10000];
	int tmp;
	while (scanf("%d", &tmp)!=-1){
		a[n]=tmp;
		n++;
	}
	int chan=0, le=0;
	for (int i=0; i<n; i++){
		if (a[i]%2==0) chan++;
		else le++;
	}
	if (chan>le) printf("CHAN");
	else if (chan<le) printf("LE");
	else printf("CHANLE");
	return 0;
}
