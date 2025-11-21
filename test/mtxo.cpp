	int c1 = 0, c2 = n-1, h1 = 0, h2 = n-1;
	int dem = 1;
	while (dem <= n*n){
		for (int i = c1; i <= c2; i++){
			a[h1][i] = dem++;
		}
		h1++;
		for (int i = h1; i <= h2; i++){
			a[i][c2] = dem++;
		}
		c2--;
		for (int i = c2; i >= c1; i--){
			a[h2][i] = dem++;
		}
		h2--;
		for (int i = h2; i>=h1; i--){
			a[i][c1] = dem++;
		}
		c1++;
	}