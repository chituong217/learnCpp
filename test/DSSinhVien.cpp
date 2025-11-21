#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

struct SinhVien{
    char id[9];
    char name[51];
    double gpa;
};

bool LoadSinhVien(istream &in, SinhVien &sv){
    if (!(in >> sv.id)){
        return false;
    }
    in.ignore();
    if (!(in.getline(sv.name, 51))){
        return false;
    }
    if (!(in >> sv.gpa)){
        return false;
    }
    return true;
}


int LoadDanhSach(istream &in, SinhVien ds[], int max){
    int cnt = 0;
    while (cnt < max && LoadSinhVien(in, ds[cnt])) {
        cnt++;
    }
    return cnt;
}

void PrintSinhVien(ostream &out, const SinhVien &sv){
    out << "MSSV: ";
    out << sv.id << " - ";
    out << "Ten: ";
    out <<sv.name << " - ";
    out << "Diem: ";
    out << fixed << setprecision(2) << sv.gpa;
}

void PrintDanhSach(ostream &out, SinhVien ds[], int max){
    for (int i=0; i < max; i++){
        PrintSinhVien(out, ds[i]);
        cout << endl;
    }
}

int SoSanhDiem(const SinhVien &a, const SinhVien &b){
    if (a.gpa > b.gpa)
        return  1;
    else if (a.gpa < b.gpa)
        return -1;
    else
        return 0;
}

void HoanVi(SinhVien &a, SinhVien &b){
    SinhVien tmp = a;
    a = b;
    b = tmp;
}

void SapXepTheoDiem(SinhVien ds[], int siSo){
    for (int i=0; i < siSo; i++){
        int min_pos = i;
        for (int j = i+1; j < siSo; j++){
            if (SoSanhDiem(ds[j], ds[min_pos]) == 1){
                min_pos = j;
            }
        }
        HoanVi(ds[i], ds[min_pos]);
    }
}


int main()
{
    const char pathin[] = "C:\\Users\\XAOXIN\\Documents\\c++\\test\\input.txt";
    ifstream fin;
    fin.open(pathin);

    if (!fin.is_open())
    {
        cout << "Khong mo duoc file " << pathin << endl;
        return 1;
    }

    SinhVien lopHoc[100]; 
    int siSo = 0;

    siSo = LoadDanhSach(fin, lopHoc, 100);
    fin.close();

    cout << "Danh sach lop co " << siSo << " sinh vien (chua sap xep):" << endl;
    cout << "---------------------------------------------------" << endl;
    PrintDanhSach(cout, lopHoc, siSo);
    cout << "---------------------------------------------------" << endl << endl;

    SapXepTheoDiem(lopHoc, siSo);

    cout << "Danh sach lop (da sap xep theo diem giam dan):" << endl;
    cout << "---------------------------------------------------" << endl;
    PrintDanhSach(cout, lopHoc, siSo);
    cout << "---------------------------------------------------" << endl;

    return 0;
}