#include <iostream>
using namespace std;

// 1. Abstract Product (Interface)
class Button {
public:
    virtual void render() = 0; 
};

// 2. Concrete Products
class WinButton : public Button {
public:
    void render() override { cout << "Rendering Windows Style Button" << endl; }
};

class MacButton : public Button {
public:
    void render() override { cout << "Rendering Mac Style Button" << endl; }
};

// 3. Abstract Factory (Yehi Abstract Design Pattern ka core hai)
class GUIFactory {
public:
    virtual Button* createButton() = 0; 
};

// 4. Concrete Factories
class WinFactory : public GUIFactory {
public:
    Button* createButton() override { return new WinButton(); }
};

class MacFactory : public GUIFactory {
public:
    Button* createButton() override { return new MacButton(); }
};

// Client logic sirf Abstract Interfaces pe depend karta hai
void ApplicationContext(GUIFactory* factory) {
    Button* btn = factory->createButton();
    btn->render();
    delete btn;
}

int main() {
    // Yahan hum OS detect karke factory assign kar rahe hain
    int osType = 1; // Assume 1 for Win, 2 for Mac
    GUIFactory* factory = nullptr;

    if (osType == 1) {
        factory = new WinFactory();
    } else {
        factory = new MacFactory();
    }

    // Client/Application ko nahi pata underlying Button WinButton hai ya MacButton
    // Yeh "Abstract Design" ki power hai
    ApplicationContext(factory);

    delete factory;
    return 0;
}



// assume we have to make UI framework jo Windows aur Mac dono ke liye Button render kare. Hum client code mein check nahi karenge ki OS konsa hai, balki Abstract Factory logic handle karegi