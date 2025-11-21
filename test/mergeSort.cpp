void merge(int a[], int l, int m, int r){
	int n1 = m-l+1, n2= r-m;
	int x[n1], y[n2];
	for (int i=0; i<n1; i++){
		x[i]= a[l+i];
	}
	for (int i=0; i<n2; i++){
		y[i]= a[m+i+1];
	}
	int i=0, j=0, idx=l;
	while (i<n1 && j<n2){
		if (x[i]<=y[j]){
			a[idx++]=x[i++];
		}
		else a[idx++]= y[j++];
	}
	while (i<n1) {
		a[idx++]=x[i++];
	}
	while (j<n2) {
		a[idx++]=y[j++];
	}
}

void mergeSort(int a[], int l, int r){
	if (l<r){
		int m = (l+r)/2;
		mergeSort(a, l, m);
		mergeSort(a, m+1, r);
		merge(a, l, m, r);
	}
}
