/*
Run-time polymorphism is achieved using Function Overriding and the mighty virtual keyword.

1. The Core Problem: Early Binding
If you create a Base class pointer but store a Derived class object inside it (a process called Upcasting), the compiler gets confused when you call a method.

// C++ code
Shape* s = new Circle();
s->draw(); 

By default, the C++ compiler is "dumb." During compile-time, it looks strictly at the pointer's type (Shape*) and completely ignores the actual object it holds (Circle). It permanently binds the function call to the Shape class's draw() method. This is called Early Binding.

2. The Solution: The virtual Keyword and Late Binding
To fix this, we add the virtual keyword to the Base class method.
Writing virtual tells the compiler: "Do not take this function call too seriously right now. Defer the decision to run-time." At run-time, the program checks the actual object resting in memory (using internal mechanisms called the V-Table and V-PTR) and executes the correct overridden method. This is called Late Binding.
*/



#include <iostream>
using namespace std;

// ==========================================
// 1. BASE CLASS (The Interface)
// ==========================================
class Shape {
public:
    // The 'virtual' keyword enables Late Binding
    virtual void draw() {
        cout << "Generic Shape Drawing" << endl;
    }
};

// ==========================================
// 2. DERIVED CLASSES (The Implementations)
// ==========================================
class Circle : public Shape {
public:
    // 'override' is optional but good practice. It ensures you are 
    // actually overriding a base class virtual function.
    void draw() override {
        cout << "Circle is drawing" << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Rectangle is drawing" << endl;
    }
};

class Triangle : public Shape {
public:
    void draw() override {
        cout << "Triangle is drawing" << endl;
    }
};

// ==========================================
// 3. THE POLYMORPHIC FUNCTION
// ==========================================
// This single function can accept ANY shape. Because 'draw()' is virtual, 
// it will dynamically call the correct method at run-time.
void shapeDrawing(Shape* s) {
    s->draw(); 
}

// ==========================================
// 4. MAIN EXECUTION
// ==========================================
int main() {
    
    // Creating specific shape objects dynamically on the heap
    Circle* c = new Circle();
    Rectangle* r = new Rectangle();
    Triangle* t = new Triangle();

    cout << "=== RUN-TIME POLYMORPHISM IN ACTION ===" << endl;

    // Passing Derived class pointers into a Base class pointer argument (Upcasting).
    // Because draw() is virtual, the program smartly resolves the exact object type at run-time.
    shapeDrawing(c); // Output: Circle is drawing
    shapeDrawing(r); // Output: Rectangle is drawing
    shapeDrawing(t); // Output: Triangle is drawing

    // Clean up heap memory
    delete c;
    delete r;
    delete t;

    return 0;
}


// Output:
// === RUN-TIME POLYMORPHISM IN ACTION ===
// Circle is drawing
// Rectangle is drawing
// Triangle is drawing