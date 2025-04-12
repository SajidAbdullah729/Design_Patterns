// Design Pattern: Decorator
// Adds responsibilities to objects dynamically without modifying their class.
// Used in UI frameworks, text formatting, beverages customization, etc.

#include <bits/stdc++.h>
using namespace std;

// Base Component
class Coffee {
public:
    virtual string getDescription() = 0;
    virtual int cost() = 0;
    virtual ~Coffee() {}
};

// Concrete Component
class BasicCoffee : public Coffee {
public:
    string getDescription() override {
        return "Basic Coffee";
    }
    int cost() override {
        return 5;
    }
};

// Base Decorator
class CoffeeDecorator : public Coffee {
protected:
    Coffee* coffee;
public:
    CoffeeDecorator(Coffee* c) : coffee(c) {}
    virtual ~CoffeeDecorator() { delete coffee; }
};

// Concrete Decorators
class Milk : public CoffeeDecorator {
public:
    Milk(Coffee* c) : CoffeeDecorator(c) {}
    string getDescription() override {
        return coffee->getDescription() + ", Milk";
    }
    int cost() override {
        return coffee->cost() + 2;
    }
};

class Sugar : public CoffeeDecorator {
public:
    Sugar(Coffee* c) : CoffeeDecorator(c) {}
    string getDescription() override {
        return coffee->getDescription() + ", Sugar";
    }
    int cost() override {
        return coffee->cost() + 1;
    }
};

int main() {
    Coffee* coffee = new BasicCoffee();        // $5
    coffee = new Milk(coffee);                 // +$2
    coffee = new Sugar(coffee);                // +$1

    cout << coffee->getDescription() << "\n";
    cout << "Total Cost: $" << coffee->cost() << "\n";

    delete coffee;
    return 0;
}

/*
Output:
Basic Coffee, Milk, Sugar
Total Cost: $8
*/
