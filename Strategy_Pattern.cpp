// Design Pattern: Strategy
// Enables selecting an algorithm at runtime.
// Used when multiple algorithms can be chosen dynamically (e.g., sorting, payment systems)

#include <bits/stdc++.h>
using namespace std;

class Strategy {
public:
    virtual void execute() = 0;
};

class StrategyA : public Strategy {
public:
    void execute() override {
        cout << "Executing Strategy A\n";
    }
};

class StrategyB : public Strategy {
public:
    void execute() override {
        cout << "Executing Strategy B\n";
    }
};

class Context {
    Strategy* strategy;
public:
    Context(Strategy* s) : strategy(s) {}
    void setStrategy(Strategy* s) {
        strategy = s;
    }
    void performTask() {
        strategy->execute();
    }
};

int main() {
    StrategyA sa;
    StrategyB sb;

    Context context(&sa);
    context.performTask(); // A

    context.setStrategy(&sb);
    context.performTask(); // B

    return 0;
}

/*
Output:
Executing Strategy A
Executing Strategy B
*/
