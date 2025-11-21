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
    if (in.fail() || in.eof()){
        return false;
    }
    in >> sv.id;
    in.ignore();
    in.getline(sv.name, 51);
    in >> sv.gpa;
    return true;
}

void PrintSinhVien(ostream &out, const SinhVien &sv){
    out << "MSSV: ";
    out << sv.id << " - ";
    out << "Ten: ";
    out <<sv.name << " - ";
    out << "Diem: ";
    out << fixed << setprecision(2) << sv.gpa;
}

int SoSanhDiem(const SinhVien &a, const SinhVien &b){
    if (a.gpa > b.gpa)
        return  1;
    else if (a.gpa < b.gpa)
        return -1;
    else
        return 0;
}


int main(){
    const char pathin[] = "input.txt";
    ifstream fin;
    fin.open(pathin);

    if (!fin.is_open())
    {
        cout << "Khong mo duoc file " << pathin << endl;
        return 1;
    }

    SinhVien svBest;
    SinhVien svTemp;
    bool isFirstStudent = true;

    cout << "Bat dau doc file..." << endl;
    while (LoadSinhVien(fin, svTemp))
    {
        cout << "Da doc: " << svTemp.name << endl;
        
        if (isFirstStudent)
        {
            svBest = svTemp; 
            isFirstStudent = false;
        }
        else
        {
            if (SoSanhDiem(svTemp, svBest) == 1)
            {
                svBest = svTemp;
            }
        }
    }

    fin.close();
    cout << "--------------------" << endl;

    if (isFirstStudent)
    {
        cout << "File rong, khong co sinh vien." << endl;
    }
    else
    {
        cout << "Sinh vien co diem cao nhat:" << endl;
        PrintSinhVien(cout, svBest);
        cout << endl;
    }

    return 0;
}