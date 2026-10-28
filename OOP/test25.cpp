#include <bits/stdc++.h>

using namespace std;

class PaymentMethod{
private:
    int money;
public:
    PaymentMethod(){
        money = 0;
    }

    PaymentMethod(int money){
        this->money = money;
    }

    int getMoney(){
        return money;
    }

    virtual void pay() = 0;
    virtual ~PaymentMethod() = default;
};

class CashPayment : public PaymentMethod{
public:
    CashPayment() : PaymentMethod(){

    }
    CashPayment(int money) : PaymentMethod(money){

    }

    void pay() override{
        cout << "Phuong thuc thanh toan: Cash" << endl;
        cout << "So tien thanh toan: " << getMoney() << endl; 
    }
};

class CardPayment : public PaymentMethod{
public:
    CardPayment() : PaymentMethod(){
        
    }
    CardPayment(int money) : PaymentMethod(money){

    }

    void pay() override{
        cout << "Phuong thuc thanh toan: Card" << endl;
        cout << "So tien thanh toan: " << getMoney() << endl; 
    }
};

class EWalletPayment : public PaymentMethod{
public:
    EWalletPayment() : PaymentMethod(){
        
    }
    EWalletPayment(int money) : PaymentMethod(money){

    }

    void pay() override{
        cout << "Phuong thuc thanh toan: EWallet" << endl;
        cout << "So tien thanh toan: " << getMoney() << endl; 
    }
};

int main(){
    CashPayment x(100);
    CardPayment y(212);
    EWalletPayment z(999);

    vector<PaymentMethod*> v;
    v.push_back(&x);
    v.push_back(&y);
    v.push_back(&z);


    for (auto x : v){
        x->pay();
    }

    return 0;
}