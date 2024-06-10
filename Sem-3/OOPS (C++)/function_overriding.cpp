
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void makeSound() {
        cout << "The animal makes a sound" << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() {
        cout << "Meow" << endl;
    }
};

int main() {
    Animal* animal = new Animal();
    animal->makeSound();

    Cat* cat = new Cat();
    cat->makeSound();

    Animal* catAnimal = new Cat();
    catAnimal->makeSound();

    return 0;
}
