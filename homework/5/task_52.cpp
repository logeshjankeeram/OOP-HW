#include <iostream>
using namespace std;

class Road {
public:
    virtual string show() = 0;
    virtual ~Road() {}
};

class Car : public Road {
public:
    string brand, model;
    double fuelCons;
    int mileage;

    Car(string b, string m, double fc, int km) 
        : brand(b), model(m), fuelCons(fc), mileage(km) {}

    double costPerKm(double pricePerLiter) {
        return (fuelCons * pricePerLiter) / 100;
    }

    string show() override {
        return brand + " " + model + ", fuel consumption: " + to_string(fuelCons) + ", mileage: " + to_string(mileage) + ", cost per km: " + to_string(costPerKm(1.5));
    }
};

class Driver{
public:
    string name, surname;
    int id;
    Road& road;

    Driver(string n, string s, int i, Road& r) 
        : name(n), surname(s), id(i), road(r) {}

    void provide() {
        cout << "driver details:" << endl;
        cout << "name: " << name << endl;
        cout << "surname: " << surname << endl;
        cout << "ID: " << id << endl;
        cout << "car info: " << road.show() << endl;
    }
};

int main() {
    Car myCar("Toyota", "Corolla", 3.3, 11000);
    Driver driver("John", "Doe", 123456, myCar);
    driver.provide();

    return 0;
}