#include <bits/stdc++.h>

using namespace std;

class SanPham{
private:
    int nmasp;
    char* masp;
    int ntensp;
    char* tensp;
    int nnsx;
    char* nsx;
    long long gianhap;
public:
    SanPham(){
        nmasp = 0;
        masp = NULL;
        ntensp = 0;
        tensp = NULL;
        nnsx = 0;
        nsx = NULL;
        gianhap = 0;
    }
    SanPham(const SanPham &khac){
        if (nmasp != 0){
            khac.masp = new [nmasp];
            for (int i = 0; i < nmasp; i++){
                khac.masp[i] = this->masp[i];
            }
            khac.nmasp = nmasp;
        }
        if (ntensp != 0){
            khac.tensp = new [ntensp];
            for (int i = 0; i < ntensp; i++){
                khac.tensp[i] = this->tensp[i];
            }
            khac.ntensp = ntensp;
        }
        if (nnsx != 0){
            khac.nsx = new [nnsx];
            for (int i = 0; i < nnsx; i++){
                khac.nsx[i] = this->nsx[i];
            }
            khac.nnsx = nnsx;
        }
        khac.gianhap = this->gianhap;
    }
    SanPham& operator = (const SanPham &khac){
        if (khac.masp != NULL){
            delete []khac.masp;
        }
        if (khac.tensp != NULL){
            delete []khac.tensp;
        }
        if (khac.nsx != NULL){
            delete []khac.nsx;
        }

        if (nmasp != 0){
            khac.masp = new [nmasp];
            for (int i = 0; i < nmasp; i++){
                khac.masp[i] = this->masp[i];
            }
            khac.nmasp = nmasp;
        }
        if (ntensp != 0){
            khac.tensp = new [ntensp];
            for (int i = 0; i < ntensp; i++){
                khac.tensp[i] = this->tensp[i];
            }
            khac.ntensp = ntensp;
        }
        if (nnsx != 0){
            khac.nsx = new [nnsx];
            for (int i = 0; i < nnsx; i++){
                khac.nsx[i] = this->nsx[i];
            }
            khac.nnsx = nnsx;
        }
        khac.gianhap = this->gianhap;
    }

    long long tinhGiaBan(){
        return gianhap * 1.1;
    }

    ~SanPham(){
        if (masp != NULL){
            delete []masp;
            masp = NULL;
        }
        if (tensp != NULL){
            delete []tensp;
            tensp = NULL;
        }
        if (nsx != NULL){
            delete []nsx;
            nsx = NULL;
        }
        nmasp = 0;
        ntensp = 0;
        nnsx = 0;
        gianhap = 0;
    }
};

class CuaHang{
private:
    int nSP;
    SanPham* ds;
public:
    CuaHang(){
        nSP = 0;
        ds = NULL;
    }
    CuaHang(const CuaHang &khac){
        if (ds != NULL){
            khac.ds = new SanPham[nSP];
            for (int i = 0; i < nSP; i++){
                khac.ds[i](ds[i]);
            }
            khac.nSP = nSP;
        }
    }
    CuaHang& operator = (const CuaHang &khac){
        if (khac.ds != NULL){
            delete []khac.ds;
        }
        if (ds != NULL){
            khac.ds = new SanPham[nSP];
            for (int i = 0; i < nSP; i++){
                khac.ds[i](ds[i]);
            }
            khac.nSP = nSP;
        }
    }
    ~CuaHang(){
        if (ds != NULL){
            delete []ds;
            nSP = 0;
        }
    }
};

int main(){


    return 0;
}