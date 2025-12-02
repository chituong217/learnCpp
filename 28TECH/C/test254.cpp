#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct SinhVien SinhVien;
//typedef struct tinhthanh tinhthanh;

struct SinhVien{
	char name[50];
	char date[20];
	char address[20];
	double gpa;
	int idx;
};

//struct tinhthanh{
//	char name[20];
//	int fre;
//};
//
//tinhthanh b[2000];
//int idx=0;

//int comp(const void *a, const void *b){
//	SinhVien *x = (SinhVien *)a;
//	SinhVien *y = (SinhVien *)b;
//	if (strcmp(x->address, y->address) != 0){
//		return strcmp(x->address, y->address);
//	}
//	else{
//		if (x->gpa > y->gpa){
//			return -1;
//		}
//		else{
//			return 1;
//		}
//	}
//}
//
//int comp(const void *a, const void *b){
//	tinhthanh *x = (tinhthanh *)a;
//	tinhthanh *y = (tinhthanh *)b;
//	return strcmp(x->name, y->name);
//}
//
//void xoa(SinhVien a[], int &n, int x){
//	for (int i = x; i < n-1; i++){
//		a[i] = a[i+1];
//	}
//	n--;
//}

int main(){
	int n;
	scanf("%d", &n);
	SinhVien a[n];
	for (int i=0; i<n; i++){
		getchar();
		fgets(a[i].name, 50, stdin);
		(a[i].name)[strlen(a[i].name) - 1] = '\0';
		fgets(a[i].date, 20, stdin);
		(a[i].date)[strlen(a[i].date) - 1] = '\0';
		fgets(a[i].address, 20, stdin);
		(a[i].address)[strlen(a[i].address) - 1] = '\0';
		scanf("%lf", &a[i].gpa);
		a[i].idx = i;
	}
	
	for (int i=0; i<n; i++){
		char z[3][10] = {0};
		int n=0;
		char tmp[20];
		strcpy(tmp, a[i].date);
		char *token = strtok(tmp, "/");
		while(token != NULL){
			strcpy(z[n], token);
			n++;
			token = strtok(NULL, "/");
		}
		if (z[1][0] == '4'){
			printf("%s %s %s %.2lf\n", a[i].name, a[i].date, a[i].address, a[i].gpa);
		}
	}
	
	
//	for (int i=0; i<n; i++){
//		printf("%s %s %s %.2lf\n", a[i].name, a[i].date, a[i].address, a[i].gpa);
//	}
	return 0;
}
