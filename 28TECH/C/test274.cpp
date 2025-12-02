#include <iostream>

using namespace std;

int main(){
	int *a = new int[1000000000];
	int n;
	cin >> n;
	for (int i = 0; i<n; i++){
		cin >> a[i];
	}
	for (int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	delete []a;
	return 0;
}
