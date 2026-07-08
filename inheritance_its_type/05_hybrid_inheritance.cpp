/*
 * -------------------------------------------------------------
 * Author      : Kavindra Kumar
 * Topic       : Hybrid Inheritance
 * Description : Hybrid inheritance combines two or more types of inheritance. The most critical aspect of Hybrid inheritance is handling the Diamond Problem, which occurs when two child classes inherit from the same base class, and a grandchild class inherits from both child classes.
 * -------------------------------------------------------------
 */

 #include <iostream>
#include <string>

class ElectronicDevice {
private:
    std::string brand;
public:
    ElectronicDevice(std::string b) : brand(b) {
        std::cout << "ElectronicDevice Constructor Called\n";
    }
    std::string getBrand() const { return brand; }
    void setBrand(std::string b) { brand = b; }

    //destructor
    ~ElectronicDevice() {
        std::cout << "ElectronicDevice Destructor Called\n";
    }
};

// Virtual keyword prevents duplicate instances of ElectronicDevice in SmartPhone
class ComputingDevice : virtual public ElectronicDevice {
protected:
    int ramGB;
public:
    ComputingDevice(std::string b, int ram) : ElectronicDevice(b), ramGB(ram) {
        std::cout << "ComputingDevice Constructor Called\n";
    }

    // setters and getters
    void setRAM(int ram) { ramGB = ram; }
    int getRAM() const { return ramGB; }

    //destructor
    ~ComputingDevice() {
        std::cout << "ComputingDevice Destructor Called\n";
    }
};

class CameraDevice : virtual public ElectronicDevice {
protected:
    int megaPixels;
public:
    CameraDevice(std::string b, int mp) : ElectronicDevice(b), megaPixels(mp) {
        std::cout << "CameraDevice Constructor Called\n";
    }

    // setters and getters
    void setMP(int mp) { megaPixels = mp; }
    int getMP() const { return megaPixels; }

    //destructor
    ~CameraDevice() {
        std::cout << "CameraDevice Destructor Called\n";
    }
};

// Grandchild Class resolves the Diamond Problem
class SmartPhone : public ComputingDevice, public CameraDevice {
private:
    std::string os;
public:
    // Note: In virtual inheritance, the grandchild MUST directly invoke the top base constructor
    SmartPhone(std::string b, int ram, int mp, std::string operatingSystem)
        : ElectronicDevice(b), ComputingDevice(b, ram), CameraDevice(b, mp), os(operatingSystem) {
        std::cout << "SmartPhone Constructor Called\n";
        }

    void showPhoneSpecs() const {
        std::cout << "\n--- SmartPhone Specifications ---\n"
                  << "Brand: " << getBrand() << "\n" // Resolved ambiguity!
                  << "RAM: " << ramGB << " GB\n"
                  << "Camera: " << megaPixels << " MP\n"
                  << "OS: " << os << "\n";
    }

    //destructor
    ~SmartPhone() {
        std::cout << "SmartPhone Destructor Called\n";
    }
};

int main() {
    SmartPhone myPhone("Apple", 8, 48, "iOS");
    myPhone.showPhoneSpecs();

    // getter and setter usage
    myPhone.setRAM(12);
    myPhone.setMP(64);
    std::cout << "\nAfter Upgrading Specs:\n";
    myPhone.showPhoneSpecs();
    // myPhone.setOS("iOS 15"); // Note: setOs is private, so we cannot access it directly from main. We can create a public setter for OS in SmartPhone class to change the OS.

    std::cout << "\nAfter Updating OS:\n";
    myPhone.showPhoneSpecs();
    std::cout << "\n";
    return 0;
}


// An example of Hybrid Inheritance in C++ where SmartPhone inherits from both ComputingDevice and CameraDevice, which in turn inherit from ElectronicDevice. The use of virtual inheritance prevents the Diamond Problem, ensuring that there is only one instance of ElectronicDevice in SmartPhone.

// Hybrid can be a combination of the multiple and hierarchical inheritance
// ek base class se 2 drived class bana (which is multiple inheritance) and phir dono derived class se ek aur derived class bana (which is hierarchical inheritance) ==> Hybrid inheritance

// The Fix: We must use the virtual keyword during inheritance to ensure only one instance of the grandparent class attributes exists in memory


//output:
/*  
ElectronicDevice Constructor Called
ComputingDevice Constructor Called
CameraDevice Constructor Called
SmartPhone Constructor Called

--- SmartPhone Specifications ---
Brand: Apple
RAM: 8 GB
Camera: 48 MP
OS: iOS

After Upgrading Specs:

--- SmartPhone Specifications ---
Brand: Apple
RAM: 12 GB
Camera: 64 MP
OS: iOS

After Updating OS:

--- SmartPhone Specifications ---
Brand: Apple
RAM: 12 GB
Camera: 64 MP
OS: iOS

SmartPhone Destructor Called
CameraDevice Destructor Called
ComputingDevice Destructor Called
ElectronicDevice Destructor Called
*/