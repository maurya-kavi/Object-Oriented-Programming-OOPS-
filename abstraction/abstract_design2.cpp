#include<iostream>
#include<string>
using namespace std;

class Bird{
    public :
    virtual void eat() = 0;
    virtual void fly() = 0;
    virtual ~Bird() {}
};

class pigeon:public Bird{
    private:
    void eat(){
        cout<<"Pigeon is eating\n";
    }

    void fly(){
        cout<<"Pigeon is flying\n";
    }
};

class sparrow:public Bird{
    private:
    void eat(){
        cout<<"Sparrow is eating\n";
    }

    void fly(){
        cout<<"Sparrow is flying\n";
    }
};

class eagle:public Bird{
    private:
    void eat(){
        cout<<"Eagle is eating\n";
    }

    void fly(){
        cout<<"Eagle is flying\n";
    }
};

void birdDoesSomething(Bird* bird){
    bird->eat();
    bird->fly();
    bird->eat();
    bird->fly();
    bird->eat();
    cout<<endl;
}

int main(){
    Bird *b1=new pigeon();
    Bird *b2=new sparrow();
    Bird *b3=new eagle();
    
    birdDoesSomething(b1);
    birdDoesSomething(b2);
    birdDoesSomething(b3);

    return 0;
}


//output:

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

// Eagle is eating
// Eagle is flying
// Eagle is eating
// Eagle is flying
// Eagle is eating





