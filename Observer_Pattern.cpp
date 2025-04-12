// Design Pattern: Observer
// Defines a one-to-many dependency between objects.
// Used in event systems (e.g., chat apps, stock updates, GUIs)

#include <bits/stdc++.h>
using namespace std;

class Observer {
public:
    virtual void update(string message) = 0;
};

class Subject {
    vector<Observer*> observers;
    string message;

public:
    void addObserver(Observer* obs) {
        observers.push_back(obs);
    }

    void setMessage(string msg) {
        message = msg;
        notifyAll();
    }

    void notifyAll() {
        for (Observer* obs : observers)
            obs->update(message);
    }
};

class User : public Observer {
    string name;
public:
    User(string n) : name(n) {}
    void update(string message) override {
        cout << name << " received: " << message << "\n";
    }
};

int main() {
    Subject chatRoom;

    User u1("Alice");
    User u2("Bob");

    chatRoom.addObserver(&u1);
    chatRoom.addObserver(&u2);

    chatRoom.setMessage("New message in chat!");

    return 0;
}

/*
Output:
Alice received: New message in chat!
Bob received: New message in chat!
*/
