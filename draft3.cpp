// have add player at last after winning.

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class character
{
protected:
  string name;
  int health;

  int attack;

public:
  character(string n, int h, int a)
  {
    name = n;
    health = h;
    attack = a;
  }

  void remaining_health()
  {
    int damage;
    damage = (health - attack);
    cout << "Name: " << name << " | Health: " << health << " | Attack: " << attack << " | Remaining Health : " << damage << endl;
  }

  void increase_health(int value)
    {
        health += value;
        cout << name << " used inventory! Health increased by " << value << ". New Health: " << health << endl;
    }
  void showinfo()
  {
    cout << "Name: " << name << " | Health: " << health << " | Attack: " << attack << endl;
  }
};

class enemy : public character
{
public:
  enemy(string n, int h, int a) : character(n, h, a) {}
};

class player : public character
{
public:
  player(string n, int h, int a) : character(n, h, a) {}
};

int main()
{
  string action;
  int no_of_attack_by_player;
  int health_of_enemy = 100;
  int health_of_player = 100;
  int damage_by_hero;
  int damage_by_enemy;
  int no_of_attack_by_enemy;

  cout << "=== Welcome to the Mini Battle Game ===\n";
  cout << "YOU HAVE ENCOUNTERED A MYSTICAL BEAST\n";
  cout << "DEFEAT IT TO MOVE FURTHER\n";

  do
  {
    cout << "CHOOSE YOUR ACTION : \n";
    cout << "|| ATTACK || INVENTORY || RUN \n";
    cin >> action;
    if (action == "ATTACK")
    {

      srand(time(0));
      int randomNumber1 = 1 + rand() % 5;
      damage_by_hero = 10 * randomNumber1;
      health_of_enemy -= damage_by_hero;
      enemy c1("Goblin", health_of_enemy + damage_by_hero, 10 * no_of_attack_by_player);
      cout << "your selected enemy info \n";
      c1.showinfo();
      cout << "Let's start the game \n";
      cout << "after the attack the remaining health \n";
      c1.remaining_health();
      if (health_of_enemy <= 0)
      {
        cout << "congratulations you won ! \n";

        break;
      }
      cout << "now it's enemy turn to attack \n";
      // now it is for player
      damage_by_enemy = 15;
      health_of_player -= damage_by_enemy;
      player p1("Hero", health_of_player + damage_by_enemy, 10 * no_of_attack_by_enemy);
      cout << "The players info \n";

      p1.showinfo();
      cout << "after the attack the remaining health \n";
      p1.remaining_health();
      if (health_of_player <= 0)
      {
        cout << "you lost the game \n";
        break;
      }
    }
    else if (action == "INVENTORY" )
        {
            cout << "INVENTORY: Choose an option:\n";
            cout << "1. Randomize attack power (4x to 7x)\n";
            cout << "2. Increase health by 30\n";
            if(health_of_player<=50){

            int choice;
            cin >> choice;

            if (choice == 1)
            {
              srand(time(0));
              int randomNumber2 = 4 + rand() % 4;
                damage_by_hero = randomNumber2 * 10;
                health_of_enemy -= damage_by_hero;
                cout << "Hero unleashed a boosted attack of " << damage_by_hero << " damage!\n";
                c1.remaining_health(damage_by_hero);
            }
            else if (choice == 2)
            {
                p1.increase_health(30);
            }
            else
            {
                cout << "Invalid inventory option!\n";
            }
        }
        else {
            cout<<"You cannot use this action now \n";
        }
        }
        else if (action == "RUN")
        {
            cout << "You fled the battle! Game over.\n";
            return 0;
        }
        else
        {
            cout << "Invalid action. Choose again.\n";
        }
        
        

  } while (health_of_enemy >= 0 && health_of_player >= 0);
  cout << "Congratulations you won some part of your land ! \n";
  cout << "HERO HEALTH REMAINING " << health_of_player + 15 << endl;
  return 0;
}