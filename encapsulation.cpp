#include<iostream>
#include<string>
using namespace std;

// implementation of encapsulation in C++
// encapulation is the process of wrapping data members and member functions into a single unit called class. It is also known as data hiding. In encapsulation, the data members of a class are hidden from other classes and can be accessed only through the member functions of their own class. This is done to protect the data from unauthorized access and modification.


// 1. public members are accessible from anywhere in the program
// 2. private members are accessible only within the class
// 3. protected members are accessible only within the class and its derived classes



class Student {
private:
    // Private data members (cannot be accessed directly)
    string name;
    int age;
    double cgpa;

public:
    // Parameterized Constructor
    Student(string name, int age, double cgpa) {
        this->name = name;
        this->age = age;
        this->cgpa = cgpa;
    }

    // Setter for Name
    void setName(string name) {
        this->name = name;
    }

    // Getter for Name
    string getName() {
        return name;
    }

    // Setter for Age (Validation)
    void setAge(int age) {
        if (age > 0 && age <= 120)
            this->age = age;
        else
            cout << "Invalid Age!" << endl;
    }

    // Getter for Age
    int getAge() {
        return age;
    }

    // Setter for CGPA (Validation)
    void setCGPA(double cgpa) {
        if (cgpa >= 0.0 && cgpa <= 10.0)
            this->cgpa = cgpa;
        else
            cout << "Invalid CGPA!" << endl;
    }

    // Getter for CGPA
    double getCGPA() {
        return cgpa;
    }

    // Display Function
    void display() {
        cout << "Name : " << name << endl;
        cout << "Age  : " << age << endl;
        cout << "CGPA : " << cgpa << endl;
    }
};

int main() {

    Student s1("Kavi", 20, 8.2);

    cout << "Initial Details\n";
    s1.display();

    cout << "\nUpdating Details...\n";

    s1.setAge(21);
    s1.setCGPA(8);
    s1.setName("Kavindra");

    cout << "\nAfter Update\n";
    s1.display();

    cout << "\nTrying Invalid Values\n";

    s1.setAge(-5);
    s1.setCGPA(12.4);

    cout << "\nAccessing using Getters\n";

    cout << "Name : " << s1.getName() << endl;
    cout << "Age  : " << s1.getAge() << endl;
    cout << "CGPA : " << s1.getCGPA() << endl;

    return 0;
}