#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef struct SinhVien SinhVien;

struct SinhVien{
	char name[100];
	char date[100];
	char address[50];
	int diem;
	char result[50];
};

int main(){
	int n;
	scanf("%d", &n);
	SinhVien a[n];
	for (int i=0; i<n; i++){
		getchar();
		fgets(a[i].name, 100, stdin);
		(a[i].name)[strlen((a[i].name)) - 1] = '\0';
		fgets(a[i].date, 100, stdin);
		(a[i].date)[strlen((a[i].date)) - 1] = '\0';
		fgets(a[i].address, 50, stdin);
		(a[i].address)[strlen((a[i].address)) - 1] = '\0';
		int e, b, c;
		scanf("%d %d %d", &e, &b, &c);
		a[i].diem = (e+b+c);
		if (a[i].diem >=24){
			strcpy(a[i].result, "DO");
		}
		else{
			strcpy(a[i].result, "TRUOT");
		}
	}
	int max = -1e9;
	for (int i=0; i<n; i++){
		if (a[i].diem > max){
			max = a[i].diem;
		}
	}
	printf("DANH SACH THU KHOA :\n");
	for (int i=0; i<n; i++){
		if (a[i].diem == max){
			printf("%s %s %s %d\n", a[i].name, a[i].date, a[i].address, a[i].diem);
		}
	}
	printf("KET QUA XET TUYEN:\n");
	for (int i=0; i<n; i++){
		printf("%s %s %s %d %s\n", a[i].name, a[i].date, a[i].address, a[i].diem, a[i].result);
	}
	return 0;
}
