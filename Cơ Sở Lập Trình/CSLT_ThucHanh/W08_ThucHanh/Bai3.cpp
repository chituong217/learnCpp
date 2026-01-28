#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cstdio>

using namespace std;

struct PhanSo{
    int tu, mau;
};

int ucln(int a, int b){
    while (b){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

char* XuatPhanSo(PhanSo *pPs){
    static char s[1000] = "";

    PhanSo ps = pPs[0];
    
    for (int i = 1; i < 2; i++){
        ps.tu = (ps.tu * pPs[i].mau) + (pPs[i].tu * ps.mau);
        ps.mau = ps.mau * pPs[i].mau;
    }

    int uc = ucln(ps.tu, ps.mau);
    ps.tu /= uc;
    ps.mau /= uc;

    sprintf(s, "%d/%d", ps.tu, ps.mau);
    return s;
}

PhanSo* TongPhanSoTuChuoi(const char *s){
    PhanSo* pPs = new PhanSo[100];
    int idx = 0;
    char line[1000];
    strcpy(line, s);
    char* token = strtok(line, "+");
    while (token != NULL){
        char* pos = strchr(token, '/');
        *pos = '\0';
        int tu = atoi(token);
        int mau = atoi(pos + 1);
        
        pPs[idx].tu = tu;
        pPs[idx].mau = mau;
        idx++;

        token = strtok(NULL, "+");
    }
    return pPs;
}

int main(){
    PhanSo *pPs = TongPhanSoTuChuoi("14/56+24/45");
    printf("Tong cua Phan so duoc tu chuoi '14/56+24/45' la:\n");
    printf("\t%s\n", XuatPhanSo(pPs));
    
    delete []pPs;

    return 0;
}