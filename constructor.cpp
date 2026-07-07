#include<iostream>
#include<string>
using namespace std;

class Student{
    public:
    int roll_no;
    string name;
    int *age; // pointer to age

    // default constructor
    Student(){
        cout<<"default constructor called"<<endl;
    } // bydeafault roll_no and name will be initialized to 0 and "" respectively

    //parameterized constructor
    Student(int roll_no,string name){
        cout<<"parameterized constructor called"<<endl;
        // when the parameter name and the class member name are same then we can use this pointer to differentiate between them
        this->roll_no=roll_no;
        this->name=name;
    }

    /*  or
    Student(int roll, string name){
        cout<<"parameterized constructor called"<<endl;
        roll_no=roll;
        this->name=name;
    }
    */

    //copy constructor
    Student(Student &s){
        cout<<"copy constructor called"<<endl;
        roll_no=s.roll_no;
        name=s.name;
    }


    void display(){
        cout<<roll_no<<" "<<name<<endl;
    }

    int getRollNo(){
        return roll_no;
    }

    //parameterized constructor with 3 parameters
    Student(int roll_no,string name,int age){
        cout<<"parameterized constructor with 3 parameters called"<<endl;
        this->roll_no=roll_no;
        this->name=name;
        this->age=new int(age); // dynamically allocate memory for age and initialize it
    }

    void displayAge(){
        cout<<*age<<endl; // dereference the pointer to get the value of age
    }

    // destructor
    ~Student(){
        cout<<"destructor called"<<endl;
        delete age; // free the dynamically allocated memory for age
    }

};

int main(){
    Student s1; // default constructor called
    Student s2(1, "Alice"); // parameterized constructor called // stack memory allocation
    Student s3(s2); // copy constructor called  (Student s3(s2) is same as Student s3=s2)
    s1.display(); // returning -1352892344 
    s1.roll_no=0; // changing roll_no of s1 to 0
    s1.name=""; // changing name of s1 to empty string

    s1.display(); // returning 0 and empty string
    s2.display();
    s3.display();

    cout<<s2.getRollNo()<<endl; // returns 1
    cout<<s3.getRollNo()<<endl; // returns 1

    s2.roll_no = 2; // changing roll_no of s2
    cout<<s2.getRollNo()<<endl; // returns 2
    cout<<s3.getRollNo()<<endl; // still returns 1, as s3 is a copy of s2 at the time of its creation

    s3 = s2; // copy constructor called
    cout<<s3.getRollNo()<<endl; // returns 2, as s3 is now a copy of s2 after the change

    // dyanamic memory allocation
    Student *s4 = new Student(3, "Bob"); // parameterized constructor called
    s4->display();
    // delete s4;

    Student *s5 = new Student(5, "Charlie", 18); // parameterized constructor called
    s5->display();
    s5->displayAge();
    // delete s5; // destructor called for s5, freeing the dynamically allocated memory for age

    return 0; // destructor called for s1, s2, s3, freeing the memory allocated for age if any
}