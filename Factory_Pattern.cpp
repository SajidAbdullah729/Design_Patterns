// Design Pattern: Factory
// Creates objects without exposing the instantiation logic to the client.
// Used when the exact type of object to create is decided at runtime (e.g., shape generator, animal game)

#include <bits/stdc++.h>
using namespace std;

class Animal {
public:
    virtual void speak() = 0;
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Woof!\n";
    }
};

class Cat : public Animal {
public:
    void speak() override {
        cout << "Meow!\n";
    }
};

class AnimalFactory {
public:
    static Animal* createAnimal(string type) {
        if (type == "dog") return new Dog();
        else if (type == "cat") return new Cat();
        return nullptr;
    }
};

int main() {
    Animal* dog = AnimalFactory::createAnimal("dog");
    Animal* cat = AnimalFactory::createAnimal("cat");

    dog->speak();
    cat->speak();

    delete dog;
    delete cat;
    return 0;
}

/*
Output:
Woof!
Meow!
*/
