#include<iostream>
using namespace std;

class Vehicle{
    protected:
    int wheels;
    float weight;

    public:
    Vehicle(int wheels, float weight){
        this->wheels = wheels;
        this->weight = weight;
    }
    int get_wheels(){
        return wheels;
    }
    float get_weight(){
        return weight;
    }
     float load_on_wheels(){
        float load;
        load = weight/wheels;
        return load;
     }
};

class Car : public Vehicle{
    float passenger_load;
    
    public:
    Car(int wheels, float weight, float passenger_load) : Vehicle(wheels, weight){
        this->passenger_load = passenger_load;
    }
    float get_passenger_load(){
        cout << "My car carries " << passenger_load << " passengers and its weight is " << get_weight() << " kg" << endl;
        cout << "My car's wheel loading is " << load_on_wheels() << " kg per tyre " << endl;
    }
};

class Truck : public Vehicle{
    float passenger_load;
    float max_load;

    public:
    Truck(int wheels, float weight, float passenger_load, float max_load) : Vehicle(wheels, weight){
        this->passenger_load = passenger_load;
        this->max_load = max_load;
    }
    float efficiency(){
        float efficiency = (weight/max_load) * 100;
        cout << "Trailer's weight is " << get_weight() << " kg" << endl;
        cout << "Trailer's efficiency is " << efficiency << endl;
    }
};
int main(){
    Car car(4, 3500, 5);
    car.get_passenger_load();
    Truck truck(22, 12500, 1, 15000);
    truck.efficiency();
    return 0;
}