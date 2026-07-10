#if !defined(BIRD_H)
#define BIRD_H
#include <iostream>

// Abstract Class (Interface)
class Bird {
public:
    virtual void eat() = 0; // Pure Virtual Function
    virtual void fly() = 0; // Pure Virtual Function
    
    // Virtual destructor ensures proper cleanup of derived classes
    virtual ~Bird() {} 
};

class Sparrow : public Bird {
private: 
    // Private to enforce abstraction - clients MUST use the Bird pointer
    void eat() override {
        std::cout << "Sparrow is eating\n";
    }
    void fly() override {
        std::cout << "Sparrow is flying\n";
    }
};

class Eagle : public Bird {
private:
    void eat() override {
        std::cout << "Eagle is eating\n";
    }
    void fly() override {
        std::cout << "Eagle is flying\n";
    }
};

class Pigeon : public Bird {
private:
    void eat() override {
        std::cout << "Pigeon is eating\n";
    }
    void fly() override {
        std::cout << "Pigeon is flying\n";
    }
};

#endif // BIRD_H