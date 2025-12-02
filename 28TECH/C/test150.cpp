#include <stdio.h>

int partition(int a[], int l, int r){
//	thiet lap khoa pivot
	int pivot = a[r], i = l - 1;
	for (int j = l; j < r; j++){
//		kiem tra xem so dang xet co lon hon khoa pivot k, neu lon hon thi bo qua, neu be hon thi swap a[i] voi a[j]
		if (a[j] <= pivot){
			++i;
			int tmp = a[i]; a[i] = a[j]; a[j] = tmp;
		}
	}
//	ket thuc vong lap thi ++i de doi cho khoa voi i luc nay de pivot lon hon ben trai va be hon ben phai pivot
	++i;
	int tmp = a[i]; a[i] = a[r]; a[r] = tmp;
//	tra ve index cua khoa pivot de sau khi ham ket thuc, tiep tuc recursive 
	return i;
}

void quickSort(int a[], int l, int r){
//	kiem tra mang chi con 1 phan tu hay khong, neu chi con 1 phan tu thi ket thuc nhanh de quy
	if (l < r){
//		index cua khoa pivot trong vong dequy 
		int p = partition(a, l, r);
//		recursive ben trai pivot
		quickSort(a, l, p-1);
//		recursive ben phai pivot
		quickSort(a, p+1, r);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	quickSort(a, 0, n-1);
	for (int i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	return 0;
}
