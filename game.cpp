#include<iostream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;
class character{
  protected:
    string name;
    int health;
    int defense;
    int attack;
   public:
   character (string n , int h, int d, int a){
        name=n;
        health=h;
        defense=d;
        attack=a;
    }
 void remaining_health(){
    int damage=defense-attack;
    if (damage<0){
       damage=0;
    } 
    else{
        health-=damage;
    } 
    cout<<" name "<<" "<<name<<" health "<< " " <<health <<" attack " << " " <<attack << " damage " <<damage<<endl;  
  }
  void showinfo(){
    cout<<"name"<<" "<<name<<"health " <<" "<<health <<"attack " << " " <<attack<<endl; ;
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

int main (){
enemy c1("goblin",100 , 15 ,10);
  c1.remaining_health();
  
   return 0;
}