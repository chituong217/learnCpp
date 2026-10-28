#include <bits/stdc++.h>

using namespace std;

class Camera{
public:
    void sacPin(int pin){
        cout << "Sac pin " << pin << endl;
    }
    void chupAnh(){
        cout << "Chup anh!" << endl;
    }
};

class MusicPlayer{
public:
    void sacPin(){
        cout << "Dang sac pin" << endl;
    }
    void ngheNhac(){
        cout << "Nghe nhac!" << endl;
    }
};

class SmartDevice : public Camera, public MusicPlayer{
public:
    using Camera::sacPin;
    using MusicPlayer::sacPin;
};

int main(){
    SmartDevice x;
    x.chupAnh();
    x.ngheNhac();
    x.sacPin(99);
    x.sacPin();

    return 0;
}