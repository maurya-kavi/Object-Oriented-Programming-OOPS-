/*
1. Function Overloading
The Concept: You can have multiple functions in the same scope that share the exact same name, as long as their parameter lists (the number of arguments or the data types of the arguments) are different. The compiler looks at what you pass in and automatically figures out which version of the function to execute.  
*/


#include <iostream>
using namespace std;

class MathOperations {
public:
    // 1. Function taking two integers
    int sum(int x, int y) {
        cout << "Calling sum of two integers: ";
        return x + y;
    }

    // 2. Function taking three integers (Different parameter COUNT)
    int sum(int x, int y, int z) {
        cout << "Calling sum of three integers: ";
        return x + y + z;
    }

    // 3. Function taking two doubles (Different parameter TYPE)
    double sum(double x, double y) {
        cout << "Calling sum of two doubles: ";
        return x + y;
    }
};

int main() {
    MathOperations math;

    // The compiler automatically routes these to the correct function
    // based on the arguments provided.
    
    cout << math.sum(5, 10) << endl;         // Calls #1
    cout << math.sum(5, 10, 15) << endl;     // Calls #2
    cout << math.sum(5.5, 2.3) << endl;      // Calls #3

    return 0;
}

//output:
// Calling sum of two integers: 15
// Calling sum of three integers: 30
// Calling sum of two doubles: 7.8