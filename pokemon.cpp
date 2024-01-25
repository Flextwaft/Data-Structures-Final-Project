#include "pokemon.h"

pokemon::pokemon(){
  name = "";
  type1 = "";
  type2 = "";
  hp = 0;
  maxhp = 0;
  attack = 0;
  defense = 0;
  speed = 0;
  move1 = "";
  move2 = "";
  move3 = "";
  move4 = "";
  attack1 = 0;
  attack2 = 0;
  attack3 = 0;
  attack4 = 0;
}

void pokemon::setData(string n, int h, int a, int d, int s){
  name = n;
  hp = h;
  maxhp = h;
  attack = a;
  defense = d;
  speed = s;
}

void pokemon::setAttack(int a){
  attack = a;
}

void pokemon::setDefense(int d){
  defense = d;
}

void pokemon::setMoves(string m1, string m2, string m3, string m4){
  move1 = m1;
  move2 = m2;
  move3 = m3;
  move4 = m4;
}

void pokemon::setAttacks(int a1, int a2, int a3, int a4){
  attack1 = a1;
  attack2 = a2;
  attack3 = a3;
  attack4 = a4;
}

void pokemon::setMoveTypes(string t1, string t2, string t3, string t4){
  movet1 = t1;
  movet2 = t2;
  movet3 = t3;
  movet4 = t4;
}

void pokemon::setType(string t){
  type1 = t;
}
void pokemon::setType(string t1, string t2){
  type1 = t1;
  type2 = t2;
}

void pokemon::setHP(int h){
  hp = h;
}