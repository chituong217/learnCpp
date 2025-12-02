#include <iostream>
#include <string.h>


// Class : lop
// Thuoc tinh : Attribute
// Phuong thuc : Method, Behavior
// Doi tuong : Object

// constructor : Ham khoi tao
// destructor : Ham huy
// This pointer
// setter getter

// Tinh chat:
// Encapsulation : dong goi
// Access Modifier : Pham vi cua thuoc tinh
// Private
// Public
// Protected
// Static variable
// Friend function, friend class
// Forward declaration

// Operator overloading
// insertion >> extraction <<
// cout : ostream
// cin : istream

using namespace std;

class GiaoVien;
class SinhVien;


class SinhVien{
//	friend class GiaoVien;
//	Thuoc tinh va phuong thuc
	private: 
//		Thuoc tinh (Attribute)
		char id[50], name[50], date[50];
		double gpa;
	public:
		SinhVien(); // constructor
//		Phuong thuc (Method, Behavior)
//		void nhap();
//		void in();
		friend istream& operator >> (istream &in, SinhVien& a);
		friend ostream& operator << (ostream &out, SinhVien a);
//		static int dem;
//		void tangDem();
//		int getDem();
//		double getGPA();
//		friend void inThongTin (SinhVien);
		~SinhVien(); // destructor
};

//int SinhVien::dem = 0;

// Implementation

istream &operator >> (istream &in, SinhVien &a){
	cout << "Nhap id: ";
	in >> a.id;
	cout << "Nhap ten: ";
	in.ignore();
	in.getline(a.name, 50);
	cout << "Nhap ngay sinh: ";
	in >> a.date;
	cout << "Nhap diem: ";
	in >> a.gpa;
	return in;
}

ostream &operator << (ostream &out, SinhVien a){
	cout << a.id << " " << a.name << " " << a.date << " " << a.gpa << endl;
	return out;
}


//void SinhVien::nhap(){
//	cout << "Nhap id: ";
//	cin >> id;
//	cout << "Nhap ten: ";
//	cin.ignore();
//	cin.get(name, 50, '\n');
//	cout << ("Nhap ngay sinh: ");
//	cin >> date;
//	cout << "Nhap diem: ";
//	cin >> gpa;
//}
//
//void SinhVien::in(){
//	cout << "ID: " << this->id << endl;
//	cout << "Ho va ten: " << this->name << endl;
//	cout << "Ngay sinh: " << this->date << endl;
//	cout << "Diem: " << this->gpa << endl;
//}


SinhVien::SinhVien(){
//	cout << "Ham duoc khoi tao o day" << endl;
}

SinhVien::~SinhVien(){
	//	cout << "Ham duoc huy o day" << endl;
}

//class GiaoVien{
//	private:
//		char khoa[50];
//	public:
//		void update(SinhVien&);
//};
//
//void GiaoVien::update(SinhVien &a){
//	a.gpa = 0;
//}

int main(){
	SinhVien x;
	cin >> x;
	cout << x;
	
	
//	inThongTin(x);
//	int n;
//	cin >> n;
//	SinhVien a[100];
//	for (int i=0; i<n; i++){
//		a[i].nhap();
//	}
//	for (int i=0; i<n; i++){
//		cout << "STT : " << a[i].getDem() << endl;
//		a[i].in();
//		a[i].tangDem();
	return 0;
}
