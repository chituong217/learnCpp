#include <iostream>

using namespace std;

int n, a[100], final = 0;

// Khoi tao cau hinh dau tien
void ktao(){
	for (int i=1; i<=n; i++){
		a[i] = 0;
	}
}


// Sinh ra cau hinh ke tiep
void sinh(){
	int i = n;
	while(i>=1 && a[i] == 1){
		a[i] = 0;
		i--;
	}
	if (i==0){
		final = 1;
	}
	a[i] = 1;
}

int main(){
	cin >> n;
	ktao();
	while (final == 0){
		for (int i=1; i <= n; i++){
			cout << a[i];
		}
		cout << endl;
		sinh();
	}

	return 0;
}
