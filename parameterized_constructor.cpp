#include<iostream>
#include<string>
using namespace std;

// different ways to write parameterized constructor in C++

// 1. Traditional Assignment (Inside the Body)
class Employee {
public:
    int id;
    string name;

    // Traditional Assignment
    Employee(int empId, string empName) {
        id = empId;
        name = empName;
    }
};

//(Note: If the parameter names are exactly the same as the class variables, you must use the this-> pointer, e.g., this->id = id;)


// 2. Initialization List (The Industry Standard)

class Employee {
public:
    int id;
    string name;
    const int departmentCode; // Must be initialized immediately

    // Initialization List
    Employee(int id, string name, int code) : id(id), name(name), departmentCode(code) {
        // The body can be completely empty, or used for other logic
    }
};


// 3. Constructor with Default Arguments (The Hybrid)
class Employee {
public:
    int id;
    string name;

    // Default arguments provided right in the signature
    Employee(int id = 0, string name = "Unassigned") : id(id), name(name) {}
};

int main() {
    Employee e1;             // Valid: Uses id=0, name="Unassigned"
    Employee e2(101);        // Valid: Uses id=101, name="Unassigned"
    Employee e3(102, "Amit"); // Valid: Uses id=102, name="Amit"
}



// 4. Constructor Delegation (C++11 and later)
class Employee {
public:
    int id;
    string name;
    string role;

    // Target Constructor (The main one doing the heavy lifting)
    Employee(int id, string name, string role) : id(id), name(name), role(role) {}

    // Delegating Constructor (Passes the work to the Target Constructor)
    Employee(int id, string name) : Employee(id, name, "Trainee") {
        // Automatically sets role to "Trainee" by delegating the work above
    }
};

