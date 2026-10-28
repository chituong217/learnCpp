#include <bits/stdc++.h>

using namespace std;

class Vehicle{
private:
    double fuel, goodsWeight;
public:
    Vehicle(){
        fuel = 0;
        goodsWeight = 0;
    }
    Vehicle(double fuel, double goodsWeight){
        this->fuel = fuel;
        this->goodsWeight = goodsWeight;
    }

    void addGoodsWeight(double GoodsWeightNeedToAdd){
        if (GoodsWeightNeedToAdd <= 0) return;
        this->goodsWeight += GoodsWeightNeedToAdd;
    }
    void removeGoodsWeight(double GoodsWeightNeedToRemove){
        if (GoodsWeightNeedToRemove <= 0) return;
        this->goodsWeight -= GoodsWeightNeedToRemove;
    }
    void addFuel(double fuelAmountNeedToAdd){
        if (fuelAmountNeedToAdd <= 0) return;
        this->fuel += fuelAmountNeedToAdd;
    }
    void removeFuel(double fuelAmountNeedToRemove){
        if (fuelAmountNeedToRemove <= 0) return;
        this->fuel -= fuelAmountNeedToRemove;
    }
    double getFuel(){
        return fuel;
    }
    double getWeight(){
        return goodsWeight;
    }

    virtual void run(double km) = 0;
    virtual ~Vehicle() = default;
};

class MotorBike : public Vehicle{
public:
    void run(double km) override{
        if (km > 0){
            double tmp1 = 2.0 * (km / 100);
            if  (getFuel() < tmp1){
                cout << "Khong du xang de chay" << endl;
            }
            else removeFuel(tmp1);
        }
        if (getWeight() > 0){
            double tmp2 = 0.1 * (getWeight() /10);
            if  (getFuel() < tmp2){
                cout << "Khong du xang de chay" << endl;
            }
            else removeFuel(tmp2);
        }
    }
};

class Truck : public Vehicle{
public:
    void run(double km) override{
        if (km > 0){
            double tmp1 = 20.0 * (km / 100);
            if  (getFuel() < tmp1){
                cout << "Khong du xang de chay" << endl;
            }
            else removeFuel(tmp1);
        }
        if (getWeight() > 0){
            double tmp2 = 1.0 * (getWeight() /1000);
            if  (getFuel() < tmp2){
                cout << "Khong du xang de chay" << endl;
            }
            else removeFuel(tmp2);
        }
    }
};

int main(){
    return 0;
}