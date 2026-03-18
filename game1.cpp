#include <iostream>
#include <string>
using namespace std;

// Base class
class character {
protected:
    string name;
    int health;
    int damage;
    int armor;

public:
    // Constructor for character
    character(string n, int h, int d, int a) : name(n), health(h), damage(d), armor(a) {}
};

// Derived class for enemy
class enemy : public character {
public:
    // Constructor explicitly initializing the base class
    enemy(string n, int h, int d, int a) : character(n, h, d, a) {}
};

// Derived class for player
class player : public character {
public:
    // Constructor explicitly initializing the base class
    player(string n, int h, int d, int a) : character(n, h, d, a) {}
};

int main() {
    // Creating an enemy and player object
    enemy e("EnemyName", 100, 20, 5);
    player p("PlayerName", 150, 30, 10);

    cout << "Objects created successfully!" << endl;
    return 0;
}
