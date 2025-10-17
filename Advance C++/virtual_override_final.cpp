#include <iostream>
using namespace std;

class Animal {
public:
    void speak() {
        cout << "Animal speaks" << endl;
    }
};

class Dog : public Animal {
public:
    virtual void speak() {
        cout << "Dog barks" << endl;
    }
};
class puppy : public Dog {
public:
    void hello() {
        cout << "Puppy says hello" << endl;
    }
    void speak() override final {
        cout << "Puppy yaps" << endl;
    }
};

int main() {
    Dog* a;        // base class pointer
    Dog d;            // derived class object
    puppy p;         // another derived class object
    a = &p;
    Animal* b = &d; // base class pointer to derived class object
    a->speak();
    b->speak();
    p.hello();

}
