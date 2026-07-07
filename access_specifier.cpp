#include <iostream>
#include  <string>

using namespace std;

// learn about access specifiers in C++
class Student{
    public:
        int roll_no;
        string name;
        int age;
    private:
        int marks;
    protected:
        int standard;
};

int main(){
    Student s1;
    s1.roll_no=1;
    s1.name="Alice";
    s1.age=10;
    // s1.standard=5; // error: 'int Student::standard' is protected within this context
    // s1.marks=90; // error: 'int Student::marks' is private within this context

    return 0;
}

// public: accessible from anywhere in the program
// private: accessible only within the class
// protected: accessible only within the class and its derived classes ( more in the inheritance chapter)

// we use getters and setters to access private members of a class. ( use for both private and protected members)


// Access specifiers in inheritance

/*
1. Public Inheritance (public)

- Public members of the base class remain public in the derived class.
- Protected members of the base class remain protected in the derived class.
- Private members of the base class are not directly accessible in the derived class.

2. Private Inheritance (private)

- Public members of the base class become private in the derived class.
- Protected members of the base class become private in the derived class.
- Private members of the base class are not directly accessible in the derived class.

3. Protected Inheritance (protected)

- Public members of the base class become protected in the derived class.
- Protected members of the base class remain protected in the derived class.
- Private members of the base class are not directly accessible in the derived class.
*/