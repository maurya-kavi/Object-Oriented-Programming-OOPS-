/*
 * -------------------------------------------------------------
 * Author      : Kavindra Kumar
 * Topic       : Multiple Inheritance
 * Description : Demonstrates inheritance of members from multiple base classes.
 * -------------------------------------------------------------
 */


#include <iostream>
#include <string>

class Engine {
private:
    int horsepower;
public:
//constructor
    Engine(int hp) : horsepower(hp) {}
    
//setters and getters
    void setHP(int hp) { horsepower = hp; }

    int getHP() const { return horsepower; }
};

class Texture {
private:
    std::string color;
public:
    Texture(std::string c) : color(c) {}
    void setColor(std::string c) { color = c; }
    std::string getColor() const { return color; }
};

// Multiple Inheritance
class SportsCar : public Engine, public Texture {
private:
    std::string modelName;
public:
    SportsCar(int hp, std::string c, std::string model) 
        : Engine(hp), Texture(c), modelName(model) {}

    void setModel(std::string model) { modelName = model; }
    std::string getModel() const { return modelName; }

    void showSpecs() const {
        std::cout << "Model: " << modelName << "\n"
                  << "Horsepower: " << getHP() << " HP\n" // From Engine
                  << "Color: " << getColor() << "\n";     // From Texture
    }
};

int main() {
    SportsCar ferrari(720, "Red", "F8 Tributo");
    ferrari.showSpecs();
    return 0;
}


//output:
// Model: F8 Tributo
// Horsepower: 720 HP
// Color: Red