#include <iostream>
#include "bird.h"

// The client function only interacts with the generic Interface
void birdDoesSomething(Bird* bird) {
    bird->eat();
    bird->fly();
    bird->eat();
    bird->fly();
    bird->eat();
}

int main() {
    // Bird* b = new Bird(); // ERROR: Cannot instantiate an abstract class

    // Upcasting: Storing a derived object in a base interface pointer
    Bird* bird = new Pigeon(); 
    
    // Passing the interface to the client logic
    birdDoesSomething(bird);

    Bird* bird2 = new Sparrow();
    birdDoesSomething(bird2);

    // Clean up heap memory
    delete bird;
    
    return 0;
}

//output
// Pigeon is eating
// Pigeon is flying
// Pigeon is eating
// Pigeon is flying
// Pigeon is eating
// Sparrow is eating
// Sparrow is flying
// Sparrow is eating
// Sparrow is flying
// Sparrow is eating
