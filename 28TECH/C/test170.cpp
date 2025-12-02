#include <stdio.h>
#define ll long long

int bS(ll a[], int n, ll x){
	int l = 0, r = n-1;
	while (l <= r){
		int m = (l + r)/2;
		if (a[m] == x) return 1;
		else if ( a[m] > x) r = m-1;
		else l = m+1;
	}
	return 0;
}

int partition (ll a[], int l, int r){
	ll pivot = a[r];
	int i=l-1;
	for (int j=l; j<r; j++){
		if (a[j] < pivot){
			i++;
			ll tmp = a[i]; a[i] = a[j]; a[j] = tmp;
		}
	}
	i++;
	ll tmp = a[i]; a[i] = a[r]; a[r] = tmp;
	return i;
}

void quickSort(ll a[], int l, int r){
	if ( l < r){
		ll p = partition(a, l, r);
		quickSort(a, l, p-1);
		quickSort(a, p+1, r);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	ll a[n];
	for (int i=0; i<n; i++){
		scanf("%lld", &a[i]);
	}
	for (int i=0; i<n; i++){
		a[i]= a[i]*a[i];
	}
	quickSort(a, 0, n-1);
	int stop = 0;
	for (int i=n-1; i>=2; i--){
		if (stop>0) break;
		for (int j=0; j<= i; j++){
			if (bS(a, n, (a[i] - a[j])) == 1) {
				printf("YES");
				stop++;
				break;
			}
		}
	}
	if (stop == 0) printf("NO");
	return 0;
}
