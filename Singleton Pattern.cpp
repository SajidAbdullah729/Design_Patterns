// Design Pattern: Singleton
//  Ensures only one instance of a class exists.
//  Used when you need exactly one object to coordinate actions across the system (e.g., Logger, Configuration Manager)

#include <bits/stdc++.h>
using namespace std;

class Singleton {
private:
    static Singleton* instance;
    Singleton() {
        cout << "Singleton Constructor Called\n";
    }

public:
    static Singleton* getInstance() {
        if (!instance)
            instance = new Singleton();
        return instance;
    }

    void showMessage() {
        cout << "Hello from Singleton\n";
    }
};

Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    s1->showMessage();
    cout << "Same instance? " << (s1 == s2) << "\n"; // true

    return 0;
}

/*
Output:
Singleton Constructor Called
Hello from Singleton
Same instance? 1
*/
