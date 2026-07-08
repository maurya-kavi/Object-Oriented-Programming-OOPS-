/*
 * -------------------------------------------------------------
 * Author      : Kavindra Kumar
 * Topic       : Multilevel Inheritance
 * Description : Demonstrates inheritance of members through multiple levels of classes.
 * -------------------------------------------------------------
 */

#include <iostream>
#include <string>

class FoodItem {
private:
    int calories;
public:
    FoodItem(int cal) : calories(cal) {}
    int getCalories() const { return calories; }
    void setCalories(int cal) { calories = cal; }
};

// Level 1 Derivation
class BakeryProduct : public FoodItem {
private:
    bool containsEgg;
public:
    BakeryProduct(int cal, bool egg) : FoodItem(cal), containsEgg(egg) {}
    bool getContainsEgg() const { return containsEgg; }
};

// Level 2 Derivation (Multilevel)
class Cake : public BakeryProduct {
private:
    std::string flavor;
public:
    Cake(int cal, bool egg, std::string flv) 
        : BakeryProduct(cal, egg), flavor(flv) {}

    void sliceDetails() const {
        std::cout << "Cake Flavor: " << flavor << "\n"
                  << "Eggless: " << (getContainsEgg() ? "No" : "Yes") << "\n"
                  << "Energy: " << getCalories() << " kcal\n";
    }
};

int main() {
    Cake chocoCake(450, false, "Chocolate Fudge");
    chocoCake.sliceDetails();
    return 0;
}


// Output:
// Cake Flavor: Chocolate Fudge
// Eggless: Yes
// Energy: 450 kcal

// first , base class will be initalized then drived class will be initalized. 