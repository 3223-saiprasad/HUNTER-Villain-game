
// ADD INVENTORY USAGE HERE AND ALSO JOIN GRID FOR RUN OPTION

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

    void remaining_health(int damage)
    {
        health -= damage;
        cout << "Name: " << name << " | Health: " << health << " | Attack: " << attack << " | Remaining Health: " << health << endl;
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
    int no_of_attack_by_player = 0;
    int health_of_enemy = 100;
    int health_of_player = 100;
    int damage_by_hero;
    int damage_by_enemy;
    int no_of_attack_by_enemy = 0;

    srand(time(0)); // Ensuring proper randomization before the loop

    enemy c1("Goblin", health_of_enemy, 10);
    player p1("Hero", health_of_player, 10);

    cout << "=== Welcome to the Mini Battle Game ===\n";
    cout << "YOU HAVE ENCOUNTERED A MYSTICAL BEAST\n";
    cout << "DEFEAT IT TO MOVE FURTHER\n";

    while (health_of_enemy > 0 && health_of_player > 0)
    {
        cout << "CHOOSE YOUR ACTION : \n";
        cout << "|| ATTACK || INVENTORY || RUN \n";
        cin >> action;

        if (action == "ATTACK")
        {
            no_of_attack_by_player++;
            int randomNumber1 = 1 + rand() % 5;
            damage_by_hero = 10 * randomNumber1;
            health_of_enemy -= damage_by_hero;
            
            cout << "Your selected enemy info:\n";
            c1.showinfo();
            
            cout << "After the attack, the remaining health:\n";
            c1.remaining_health(damage_by_hero);

            if (health_of_enemy <= 0)
            {
                cout << "Congratulations, you won!\n";

                // Creating a new player after winning
                player winner("New Champion", health_of_player, 50);
                cout << "A new hero has emerged!\n";
                winner.showinfo();
                return 0;
            }

            cout << "Now it's the enemy's turn to attack.\n";
            
            // Enemy attacks player
            no_of_attack_by_enemy++;
            damage_by_enemy = 15;
            health_of_player -= damage_by_enemy;
            
            cout << "The player's info:\n";
            p1.showinfo();
            cout << "After the attack, the remaining health:\n";
            p1.remaining_health(damage_by_enemy);

            if (health_of_player <= 0)
            {
                cout << "You lost the game.\n";
                return 0;
            }
        }
        else if (action == "INVENTORY")
        {
            // -----------------------------------------------------------------------//
            cout << "Inventory is empty for now! Get back to battle!\n";
        }
        else if (action == "RUN")
        {
            // ----------------------------------------------------------------------//
            cout << "You fled the battle! Game over.\n";
            return 0;
        }
        else
        {
            cout << "Invalid action. Choose again.\n";
        }
    }

    cout << "Congratulations, you won some part of your land!\n";
    cout << "HERO HEALTH REMAINING " << health_of_player << endl;
    
    return 0;
}