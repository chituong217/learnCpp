#include <bits/stdc++.h>

using namespace std;

class Notification{
public:
    virtual void send() = 0;
    virtual ~Notification() = default;
};

class EmailNotification : public Notification{
public:
    void send() override{
        cout << "Sending email notification..." << endl;
    }
};

class SmsNotification : public Notification{
public:
    void send() override{
        cout << "Sending SMS notification..." << endl;
    }
};

int main(){
    EmailNotification a;
    SmsNotification b;

    vector<Notification*> v;
    v.push_back(&a);
    v.push_back(&b);

    for (auto x : v){
        x->send();
    }

    return 0;
}