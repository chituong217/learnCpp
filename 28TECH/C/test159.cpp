#include <stdio.h>

int partition (int a[], int l, int r){
	int pivot = a[r]; int i = l-1;
	for (int j=l; j<r; j++){
		if (a[j] <= pivot){
			++i;
			int tmp=a[i]; a[i]= a[j]; a[j]= tmp;
		}
	}
	++i;
	int tmp = a[i]; a[i] = a[r]; a[r] = tmp;
	return i;
}

void quickSort (int a[], int l, int r){
	if (l < r){
		int p = partition(a, l, r);
		quickSort(a, l, p-1);
		quickSort(a, p+1, r);
	}
}

void tachmang(int a[], int n){
	int chan[n], le[n];
	int j=0, k=0;
	for (int i=0; i<n; i++){
		if (a[i] %2==0){
			chan[j] = a[i];
			j++;
		}
		else {
			le[k] = a[i];
			k++;
		}
	}
	quickSort(chan, 0, j-1);
	quickSort(le, 0, k-1);
	int cnt = k-1;
	for (int i=0; i<k; i++){
		a[i] = le[cnt];
		cnt--;
	}
	cnt=0;
	for (int i=k; i<n; i++){
		if (cnt==j) break;
		a[i] = chan[cnt];
		cnt++;
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	tachmang(a, n);
	for (int i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	return 0;
}
