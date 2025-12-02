#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct SinhVien{
	char ten[100];
	char lop[100];
	double gpa;
};

typedef struct SinhVien SinhVien;


void nhap(SinhVien *ptr){
	printf("Nhap ten:");
	gets(ptr -> ten);
	printf("Nhap lop:");
	gets(ptr -> lop);
	printf("Nhap GPA:");
	scanf("%lf", &ptr -> gpa);	
}

void xuat(SinhVien x){
	printf("Ten cua sinh vien: %s\n", x.ten);
	printf("Lop cua sinh vien: %s\n", x.lop);
	printf("GPA cua sinh vien: %.2lf\n", x.gpa);
}

void timkiem(SinhVien a[], int n, char name[]){
	int find = 0;
	for (int i=0; i<n; i++){
		if ( strcmp(name, a[i].ten) == 0){
			xuat(a[i]);
			find=1;
		}
	}
	if (find != 1){
		printf("Khong tim thay sinh vien co ten nay!\n");
	}
}

void diemgpacaonhat(SinhVien a[], int n){
	double gpa_max = 0;
	for (int i=0; i<n; i++){
		gpa_max = fmax(gpa_max, a[i].gpa);
	}
	for (int i=0; i<n; i++){
		if (gpa_max == a[i].gpa){
			xuat(a[i]);
		}
	}
}

void sapxep(SinhVien a[], int n){
	for (int i=0; i<n; i++){
		int min_pos = i;
		for (int j=i+1; j<n; j++){
			if (a[j].gpa < a[i].gpa){
				min_pos = j;
			}
		}
		SinhVien tmp = a[i]; a[i] = a[min_pos]; a[min_pos] = tmp;
	}
}

int main(){
	int n;
	printf("Nhap vao so luong sinh vien:");
	scanf("%d", &n);
	getchar();
	SinhVien a[n];
	for (int i=0; i<n; i++){
		nhap(&a[i]);
		getchar();
	}
//	printf("Nhap vao ten can tim kiem:");
//	char name[1000];
//	gets(name);
//	timkiem(a, n, name);
	sapxep(a, n);
	for (int i=0; i<n; i++){
		xuat(a[i]);
	}
	return 0;
}
