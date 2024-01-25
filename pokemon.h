#pragma once
#include <iostream>

using namespace std;

class pokemon
{
public:
  pokemon();
  //setters
  void setData(string n, int h, int a, int d, int s);
  void setAttack(int a);
  void setDefense(int d);
  //sets pokemons moves data
  void setMoves(string m1, string m2, string m3, string m4);
  void setAttacks(int a1, int a2, int a3, int a4);
  void setMoveTypes(string t1, string t2, string t3, string t4);
  void setType(string t);
  void setType(string t1, string t2);
  void setHP(int h);
  //getters
  string getName() const {return name;}
  //gets pokemons typings
  string getType1() const {return type1;}
  string getType2() const {return type2;}
  //gets pokemons move names
  string getMove1() const {return move1;}
  string getMove2() const {return move2;}
  string getMove3() const {return move3;}
  string getMove4() const {return move4;}
  //gets pokemons move type
  string getMoveT1() const {return movet1;}
  string getMoveT2() const {return movet2;}
  string getMoveT3() const {return movet3;}
  string getMoveT4() const {return movet4;}
  //gets pokemons move damage
  int getAttack1() const {return attack1;}
  int getAttack2() const {return attack2;}
  int getAttack3() const {return attack3;}
  int getAttack4() const {return attack4;}
  //get HP stats
  int getHP() const {return hp;}
  int getMaxHP() const {return maxhp;}
  //get pokemons damage
  int getAttack() const {return attack;}
  //get pokemons defense
  int getDefense() const {return defense;}
  //gets pokemons speed
  int getSpeed() const {return speed;}

private:
  string name, type1, type2;
  string move1, move2, move3, move4;
  string movet1, movet2, movet3, movet4;
  int attack1, attack2, attack3, attack4;
  int hp, maxhp, attack, defense, speed;
};