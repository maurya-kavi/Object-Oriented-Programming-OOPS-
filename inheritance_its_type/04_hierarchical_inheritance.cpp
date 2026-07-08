/*
 * -------------------------------------------------------------
 * Author      : Kavindra Kumar
 * Topic       : Hierarchical Inheritance
 * Description : Demonstrates inheritance of members from a base class to multiple derived classes.
 * -------------------------------------------------------------
 */

 #include <iostream>
#include <string>

class Employee {
private:
    int id;
    double salary;
public:
    Employee(int empId, double sal) : id(empId), salary(sal) {}
    
    int getId() const { return id; }
    double getSalary() const { return salary; }
    void setSalary(double sal) { salary = sal; }
};

// Hierarchical Branch 1
class Developer : public Employee {
private:
    std::string favLanguage;
public:
    Developer(int id, double sal, std::string lang) 
        : Employee(id, sal), favLanguage(lang) {}

    void showDevProfile() const {
        std::cout << "Dev ID: " << getId() << " | Language: " << favLanguage 
                  << " | Salary: $" << getSalary() << "\n";
    }
};

// Hierarchical Branch 2
class Manager : public Employee {
private:
    int teamSize;
public:
    Manager(int id, double sal, int size) 
        : Employee(id, sal), teamSize(size) {}

    void showManagerProfile() const {
        std::cout << "Manager ID: " << getId() << " | Managing: " << teamSize 
                  << " people | Salary: $" << getSalary() << "\n";
    }
};

int main() {
    Developer dev(101, 95000, "C++");
    Manager mgr(102, 120000, 8);
    
    dev.showDevProfile();
    mgr.showManagerProfile();
    return 0;
}

// ek base class se 2 ya 2 se jyada derived class bana sakte hai. thats called hierarchical inheritance.

//output:
// Dev ID: 101 | Language: C++ | Salary: $95000
// Manager ID: 102 | Managing: 8 people | Salary: $120000