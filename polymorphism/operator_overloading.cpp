/* 
2. Operator Overloading
The Concept: Standard C++ operators (like +, -, ==) know how to work with built-in data types like int or float. But if you try to add two custom Complex objects together using C = A + B, the compiler throws an error because it doesn't know how to add your custom objects.

Operator Overloading allows you to define exactly what an operator should do when applied to your custom classes.
*/


#include <iostream>
using namespace std;

class Complex {
public:
    int real;
    int imag;

    // Default Constructor
    Complex() {
        real = 0;
        imag = 0;
    }

    // Parameterized Constructor
    Complex(int r, int i) {
        real = r;
        imag = i;
    }

    // ==========================================
    // OPERATOR OVERLOADING FOR '+'
    // Syntax: ReturnType operator+(const ClassName& obj)
    // ==========================================
    Complex operator+(const Complex& B) {
        Complex temp;
        
        // 'this' refers to the object on the LEFT side of the '+' (e.g., A)
        // 'B' refers to the object on the RIGHT side of the '+'
        
        temp.real = this->real + B.real;
        temp.imag = this->imag + B.imag;
        
        return temp;
    }

    // Overloading '==' to check if two complex numbers are identical
    bool operator==(const Complex& B) {
        return (this->real == B.real && this->imag == B.imag);
    }

    // Helper method to print the complex number
    void print() {
        cout << real << " + i" << imag << endl;
    }
};

int main() {
    // Creating two complex numbers
    Complex A(3, 5); // 3 + i5
    Complex B(2, 4); // 2 + i4

    // Because we overloaded '+', the compiler translates this to A.operator+(B)
    Complex C = A + B; 

    cout << "Complex Number A: ";
    A.print();
    
    cout << "Complex Number B: ";
    B.print();
    
    cout << "Result of A + B : ";
    C.print();

    // Testing the overloaded '==' operator
    if (A == B) {
        cout << "A and B are equal!" << endl;
    } else {
        cout << "A and B are NOT equal!" << endl;
    }

    return 0;
}

// output:
// Complex Number A: 3 + i5
// Complex Number B: 2 + i4
// Result of A + B : 5 + i9
// A and B are NOT equal!