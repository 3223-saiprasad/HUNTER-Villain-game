#include<iostream>
#include<string>
using namespace std;

class character {
  protected:
    string name;
    int health;
    int defense;
    int attack;

  public:
    character(string n, int h, int d, int a) {
        name = n;
        health = h;
        defense = d;
        attack = a;
    }

    void remaining_health() {
        int damage = attack - defense;
        if (damage < 0) damage = 0;
        health -= damage;
        cout << "Name: " << name << " | Health: " << health << " | Attack: " << attack << " | Damage taken: " << damage << endl;
    }

    void showinfo() {
        cout << "Name: " << name << " | Health: " << health << " | Attack: " << attack << endl;
    }
};

class enemy : public character {
  public:
    enemy(string n, int h, int d, int a) : character(n, h, d, a) {}
};

class player : public character {
  public:
    player(string n, int h, int d, int a) : character(n, h, d, a) {}
};

int main() {
    character c1("goblin", 100, 15, 10);
    c1.remaining_health();
    return 0;
}