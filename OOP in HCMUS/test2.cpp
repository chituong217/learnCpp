#include <bits/stdc++.h>

using namespace std;

class Product{
private:
    int ID;
    char *name;
    char *category;
    float price;

public:
    Product(){
        ID = 0;
        name = nullptr;
        category = nullptr;
        price = 0;
    }
    ~Product(){
        if (name != nullptr){
            delete []name;
        }
        if (category != nullptr){
            delete []category;
        }
        name = nullptr;
        category = nullptr;
        ID = 0;
        price = 0;
    }
    Product(const Product& other){
        this->ID = other.ID;
        this->price = other.price;

        if (other.name == nullptr){
            this->name = nullptr;
        }
        else{
            int len = strlen(other.name);
            this->name = new char [len];
            for (int i = 0; i < len; i++){
                this->name[i] = other.name[i];
            }
        }

        if (other.category == nullptr){
            this->category = nullptr;
        }
        else{
            int len = strlen(other.category);
            this->category = new char [len];
            for (int i = 0; i < len; i++){
                this->category[i] = other.category[i];
            }
        }
    }

    Product& operator = (const Product& other){
        if (this == &other){
            return (*this);
        }

        if (this->name != nullptr){
            delete []this->name;
            this->name = nullptr;
        }
        if (this->category != nullptr){
            delete []this->category;
            this->category = nullptr;
        }

        this->ID = other.ID;
        this->price = other.price;

        if (other.name == nullptr){
            this->name = nullptr;
        }
        else{
            int len = strlen(other.name);
            this->name = new char [len];
            for (int i = 0; i < len; i++){
                this->name[i] = other.name[i];
            }
        }

        if (other.category == nullptr){
            this->category = nullptr;
        }
        else{
            int len = strlen(other.category);
            this->category = new char [len];
            for (int i = 0; i < len; i++){
                this->category[i] = other.category[i];
            }
        }

        return *this;
    }

    friend istream& operator >> (istream &in, Product &x){
        in >> x.ID >> x.price;
        in.ignore();

        char a[105];
        in.getline(a, 105);
        int len = strlen(a);

        x.name = new char [len];
        strcpy(x.name, a);

        in.getline(a, 105);
        len = strlen(a);

        x.category = new char [len];
        strcpy(x.category, a);

        return in;
    }

    friend ostream& operator << (ostream &out, const Product &x){
        out << x.ID << " " << x.name << " " << x.category << " " << x.price << endl;

        return out;
    }
};

int main(){


    return 0;
}