#include<iostream>
#include<string>
#include <cstdlib> // For srand() and rand()
#include <ctime>   // For time()
using namespace std;

class character {
  protected:
    string name;
    int health;
 
    int attack;

  public:
    character(string n, int h, int a) {
        name = n;
        health = h;
        attack = a;
    }

    void remaining_health_hero() {
        int damage;
        srand(time(0));

        int randomNumber1 = 15 + rand() % 6;
        damage=(health-damage);
        cout << "Name: " << name << " | Health: " << health << " | Attack: " << attack << " | Remaining Health : " << damage << endl;
    }
    void remaining_health_villain() {
        int damage;
        srand(time(0));

        int randomNumber2 = 25 + rand() % 11;
        damage=(health-damage);
        cout << "Name: " << name << " | Health: " << health << " | Attack: " << attack << " | Remaining Health : " << damage << endl;
    }

    void showinfo() {
        cout << "Name: " << name << " | Health: " << health << " | Attack: " << attack << endl;
        
    }
};

class enemy : public character {
  public:
    enemy(string n, int h, int a) : character(n, h, a) {}
};

class player : public character {
  public:
    player(string n, int h, int a) : character(n, h, a) {}
 };

 int main() {
    string name ;
    int no_of_attack_by_player;
    int health_of_enemy=100;
    int health_of_player=100;
    int damage_by_hero;
    int damage_by_enemy;
    int no_of_attack_by_enemy;

    cout << "=== Welcome to the Mini Battle Game ===\n";
    
    
    do{
      cin>>name;
      srand(time(0));

      int randomNumber1 = 1 + rand() % 5;
      damage_by_hero=10*randomNumber1;
      health_of_enemy-=damage_by_hero;
      if(health_of_enemy<=0){
         cout<<"consgratulations you won ! \n";
        break;
     }
    enemy e1(name, health_of_enemy+damage_by_hero, 10*no_of_attack_by_player);
     cout<<"your selected enemy info \n"; 
     e1.showinfo();
     cout<<"Let's start the game \n";
     cout<<"after the attack the remaining health \n";
     e1.remaining_health_villain();
     cout<<"now it's enemy turn to attack \n";
    // now it is for player 
    cout<<"enter no of attack by enemy \n";
    cout<<"with every attack the health will be reduce by 10 \n";
    cin>>no_of_attack_by_enemy;
     damage_by_enemy=10*no_of_attack_by_enemy;
     health_of_player-=damage_by_enemy;
     if(health_of_player<=0){
      cout<<"you lost the game \n";
      break;
     }
    player p1("hero",health_of_player+damage_by_enemy,10*no_of_attack_by_enemy);
    cout<<"The players info \n";

    p1.showinfo();
    cout<<"after the attack the remaining health \n";
    p1.remaining_health_hero();

    }while( health_of_enemy>0 && health_of_player>0);
        // cout<<"Congratulations you won some part of your land ! \n";
        return 0;
 
      }