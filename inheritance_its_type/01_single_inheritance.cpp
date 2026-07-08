/*
 * -------------------------------------------------------------
 * Author      : Kavindra Kumar
 * Topic       : Single Inheritance
 * Description : Demonstrates inheritance of members from one base
 *               class to one derived class.
 * -------------------------------------------------------------
 */


#include <iostream>
#include <string>

class Vehicle {
private:
    std::string brand;
protected:
    int manufacturingYear;

public:
    // Constructor
    Vehicle(std::string b, int year) : brand(b), manufacturingYear(year) {}

    // Getters and Setters
    void setBrand(std::string b) { brand = b; }
    std::string getBrand() const { return brand; }

    void setYear(int year) { manufacturingYear = year; }
    int getYear() const { return manufacturingYear; }

    void displayVehicleInfo() const {
        std::cout << "Brand: " << brand << ", Year: " << manufacturingYear << "\n";
    }
};

// Single Inheritance (Public Mode)
class Car : public Vehicle {
private:
    int seatingCapacity;

public:
    // Derived constructor passing data to Base constructor
    Car(std::string b, int year, int capacity) 
        : Vehicle(b, year), seatingCapacity(capacity) {}

    /* 
    // (or) Constructor
    Car(std::string b, int year, int capacity): Vehicle(b, year) { // Call base class constructor
        seatingCapacity = capacity;
    }
    */


    void setCapacity(int capacity) { seatingCapacity = capacity; }
    int getCapacity() const { return seatingCapacity; }

    void displayCarDetails() const {
        // Can access public and protected members of base class directly
        displayVehicleInfo(); 
        std::cout << "Class: Car, Capacity: " << seatingCapacity 
                  << ", Accessing Protected Year Directly: " << manufacturingYear << "\n";
    }
};

int main() {
    Car myCar("Tesla", 2023, 5);
    myCar.displayCarDetails();
    return 0;
}

// In this example, the Car class inherits from the Vehicle class. The Car class can access public and protected members of the Vehicle class, but not private members. The displayCarDetails() function demonstrates how to access both inherited and own members.

// Note: If you try to access the private member 'brand' of Vehicle directly in Car, it will result in a compilation error.

// Additional Notes:
// pahle base ka constructor call hoga fir derived ka constructor call hoga
// pahle drive ka destructor call hoga fir base ka destructor call hoga

// pahle base ka attribute intialize hoga fir derived ka attribute initialize hoga


