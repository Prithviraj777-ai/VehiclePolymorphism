#include<iostream>
#include<string>
using namespace std;

// Base class representing a generic Car
class Car {
protected:
    string brand;       // Brand of the car
    string model;       // Model of the car
    bool isEngineOn;    // State of the engine
    int currentSpeed;   // Current speed of the car

public:
    // Constructor to initialize car properties
    Car(string b, string m){
        this->brand = b;
        this->model = m;
        isEngineOn = false;
        currentSpeed = 0;
    }

    // Start the car engine
    void startEngine(){
        isEngineOn = true;
        cout << brand << " "  << model << " engine started" << endl;
    }

    // Stop the car engine
    void stopEngine(){
        isEngineOn = false;
        cout << brand << " " << model << " engine stopped" << endl;
    }

    // Accelerate the car if engine is on
    void accelerate(){
        if(!isEngineOn){
            cout << brand << " " << model << " engine is not on. Cannot accelerate." << endl;
            return;
        }
        currentSpeed += 20;
        cout << brand << " " << model << " accelerated to " << currentSpeed << " km/h" << endl;
    }

    // Apply brakes to reduce speed
    void brake(){
        currentSpeed -= 20;
        if(currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model << " braked to " << currentSpeed << " km/h" << endl;
    }

    // Virtual destructor for proper cleanup of derived class objects
    virtual ~Car() {}
};

// Derived class representing a Manual Car
class ManualCar : public Car {
private:
    int currentGear;    // Current gear of the manual car

public:
    // Constructor to initialize base and derived class members
    ManualCar(string b, string m) : Car(b, m){
        currentGear = 0;
    }

    // Method to shift gears
    void shiftGear(int gear){
        currentGear = gear;
        cout << brand << " " << model << " shifted to gear " << currentGear << endl;
    }
};

// Derived class representing an Electric Car
class ElectricCar : public Car {
private:
    int batteryLevel;   // Battery level percentage

public:
    // Constructor to initialize base and derived class members
    ElectricCar(string b, string m) : Car(b, m){
        batteryLevel = 100;
    }

    // Method to charge the battery
    void chargeBattery(){
        batteryLevel = 100;
        cout << brand << " " << model << " : Battery fully charged." << endl;
    }
};

// Main function demonstrating the usage of ManualCar and ElectricCar
int main(){

    // Creating a ManualCar object using dynamic memory allocation
    ManualCar* myManualCar = new ManualCar("Suzuki", "WagonR");
    myManualCar->startEngine();        // Start engine
    myManualCar->shiftGear(1);         // Shift to gear 1
    myManualCar->accelerate();         // Accelerate
    myManualCar->brake();              // Apply brake
    myManualCar->stopEngine();         // Stop engine
    delete myManualCar;                // Deallocate memory

    cout << "----------------------------------------" << endl;

    // Creating an ElectricCar object using dynamic memory allocation
    ElectricCar* myElectricCar = new ElectricCar("Tesla", "Model S");
    myElectricCar->chargeBattery();    // Charge the battery
    myElectricCar->startEngine();      // Start engine
    myElectricCar->accelerate();       // Accelerate
    myElectricCar->brake();            // Apply brake
    myElectricCar->stopEngine();       // Stop engine
    delete myElectricCar;              // Deallocate memory

    return 0;
}
