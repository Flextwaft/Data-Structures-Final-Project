/*
Author: Julio Gonzalez
Date: 05/05/2022
Title: Final Project - Pokemon
*/

#include <iostream>
#include "pokemon.h"
#include <time.h>

using namespace std;

void welcome();
void selection(pokemon team[]);
void setPokemonInfo(pokemon team[], int i, int choice);
void displayPokemon(pokemon team[]);
void setEnemy(pokemon team[], int n);
void attack(pokemon team[], int i, pokemon enemy[], int j, int choice);
void special(pokemon team[], int i, pokemon enemy[], int j);
bool fight(pokemon team[], pokemon enemy[]);
float type(string attacker, string defender1, string defender2);

int main() {
  //variable declarations
  srand(time(NULL));
  pokemon team[6], enemy[3];
  bool pass = true;
  string temp;
  //intro functions to get the players team ready. 
  welcome();
  selection(team);
  cout << "Team chosen:" << endl;
  displayPokemon(team);
  cout << "Press [Enter] to continue: ";
  cin.get();
  getline(cin, temp);
  cout << "\n\n\n";
  //first fight occurs here.
  cout << "Time for your first fight!" << endl;
  cout << "Press [Enter] to continue: ";
  getline(cin, temp);
  cout << "\n\n\n";
  setEnemy(enemy, 1);
  pass = fight(team, enemy);
  //if game won, move onto next game. Else end the game.
  if (pass){
    //second fight
    cout << "Congrats! Time for the second fight!" << endl;
    cout << "Press [Enter] to continue: ";
    getline(cin, temp);
    cout << "\n\n\n";
    setEnemy(enemy, 4);
    pass = fight(team, enemy);
    if (pass){
      //third fight
      cout << "Congrats! Time for the final fight! Good luck >:~)" << endl;
      cout << "Press [Enter] to continue: ";
      getline(cin, temp);
      cout << "\n\n\n";
      setEnemy(enemy, 7);
      pass = fight(team, enemy);
      //congrats on winning.
      if (pass){
        cout << "You passed the game!\nYou can rerun the game and try out new teams.\nThank you for playing!";
      } else {
        cout << "Aww so close :( try again.";
      }
    } else {
      cout << "Not too bad, try again with the same or new team!";
    }
  } else {
    cout << "HAHA get better pls and try again. pls";
  }
}

//fighting function
bool fight(pokemon team[], pokemon enemy[]){
  //variables
  string temp;
  int i = 0, j = 0, choice, count = 0;
  //loop to go around and around until the game is decided. 
  while(true){
    //display pokemon with their HP
    cout << team[i].getName() << ": " << team[i].getHP() << "/" << team[i].getMaxHP() << endl;
    cout << enemy[j].getName() << ": " << enemy[j].getHP() << "/" << enemy[j].getMaxHP() << endl;
    //options
    cout << "1. " << team[i].getMove1() << endl;
    cout << "2. " << team[i].getMove2() << endl;
    cout << "3. " << team[i].getMove3() << endl;
    cout << "4. " << team[i].getMove4() << endl;
    cout << "5. Switch Pokemon" << endl;
    cout << "6. Give up" << endl;
    cout << "\nEnter number of choice: ";
    cin >> choice;
    //decision
    //if they decide to attack:
    if (choice >= 1 && choice <= 4){
      attack(team, i, enemy, j, choice);
      cout << "Press [Enter] to continue: ";
      cin.get();
      getline(cin, temp);
      cout << "\n\n\n";
      //if they decide to swap pokemon
    } else if (choice == 5){
      cout << "\n\n\n";
      displayPokemon(team);
      cout << "Enter the pokemon you would like: ";
      cin >> choice;
      //input validation
      if (choice < 1 || choice > 6){
        cout << "Pokemon doesn't exist. Try again." << endl;
      } else {
        //make sure the pokemon hasn't fainted
        if (team[choice - 1].getHP() <= 0) cout << "Pokemon has fainted. Please try again." << endl;
        else i = choice - 1;
        cout << "\n\n\n";
      }
      //exits game
    } else if (choice == 6){
      cout << "\n\n\n";
      return false;
      //input validation
    } else {
      cout << "\n\n\n";
      cout << "Wrong input. Try again." << endl;
      continue;
    }
    //if the enemy faints
    if (enemy[j].getHP() == 0){
      cout << enemy[j].getName() << " has fainted." << endl;
      cout << "Press [Enter] to continue: ";
      getline(cin, temp);
      cout << "\n\n\n";
      j++;
      if (j == 3) return true;
      continue;
    }
    //Enemy attack
    attack(enemy, j, team, i, rand() % 4 + 1);
    cout << "Press [Enter] to continue: ";
    cin.get();
    getline(cin, temp);
    cout << "\n\n\n";
    //if pokemon faints
    if (team[i].getHP() == 0){
      cout << team[i].getName() << " has fainted." << endl;
      displayPokemon(team);
      cout << "Enter the pokemon you would like: ";
      cin >> choice;
      if (choice < 1 || choice > 6){
        cout << "Pokemon doesn't exist. Try again." << endl;
      } else {
        if (team[choice - 1].getHP() <= 0) cout << "Pokemon has fainted. Please try again." << endl;
        else i = choice - 1;
      }
      cout << "\n\n\n";
    }
    //makes sure my entire team hasnt fainted.
    count = 0;
    for (int l = 0; l < 6; l++){
      if (team[l].getHP() != 0) break;
      count++;
    }
    if (count == 6){
      return false;
    }
  }
}

//function to decide the attack and its damage.
void attack(pokemon team[], int i, pokemon enemy[], int j, int choice){
  string temp;
  float damage = 0;
  cout << "\n\n\n";
  cout << team[i].getName() << " used ";
  switch (choice) {
  case 1:
    cout << team[i].getMove1() << "!\n"; 
    damage = team[i].getAttack1() * (team[i].getAttack()/enemy[j].getDefense());
    break;
  case 2:
    cout << team[i].getMove2() << "!\n"; 
    damage = team[i].getAttack2() * (team[i].getAttack()/enemy[j].getDefense());
    break;
  case 3:
    cout << team[i].getMove3() << "!\n"; 
    damage = team[i].getAttack3() * (team[i].getAttack()/enemy[j].getDefense());
    break;
  default:
    cout << team[i].getMove4() << "!\n"; 
    if (team[i].getAttack4() != 0){
      damage = team[i].getAttack4() * (team[i].getAttack()/enemy[j].getDefense());
    } else {
      special(team, i, enemy, j);
      return;
    }
  }
  enemy[j].setHP(enemy[j].getHP() - damage);
  if (enemy[j].getHP() < 0) enemy[j].setHP(0);
  cout << team[i].getName() << " did " << damage << " damage! " << enemy[j].getName() << " has " << enemy[j].getHP() << " HP left!\n";
}

//set ups the enemy team.
void setEnemy(pokemon team[], int n){
  for (int i = 0; i < 3; i++){
    setPokemonInfo(team, i, n);
    n++;
  }
}

//where you actually select the pokemon you want from the catalog.
void selection(pokemon team[]){
  int choice;
  for (int i = 0; i < 6; i++){
    cout << "Please select pokemon "<< i + 1 << " from the selection below" << endl;
    cout << "1. Blaziken (Fighting, Fire)" << endl << "2. Serperior (Grass)" << endl; 
    cout << "3. Greninja (Water, Dark)" << endl << "4. Lucario (Fighting, Steel" << endl; 
    cout << "5. Garchomp (Dragon, Ground)" << endl << "6. Bisharp (Dark, Steel)" << endl; 
    cout << "7. Cinccino (Normal)" << endl << "8. Cinderace (Fire)" << endl; 
    cout << "9. Pikachu (Electric)" << endl << "10. Meowstic (Psychic)" << endl; 
    cout << "Enter the pokemons number: ";
    cin >> choice;
    cout << "\n\n\n";
    if (choice > 10 || choice < 1){
      cout << "Incorrect input. Try again.\n" << endl;
      i--;
    } else setPokemonInfo(team, i, choice);
  }
}

//welcome to the game.
void welcome(){
  string temp;
  cout << "Hello! Welcome to PVP Pokemon. Simply choose your 6 pokemon team from our catalog and start fighting!" << endl;
  cout << "You will fight against three teams so make sure to choose the best team you can!" << endl;
  cout << "Press [Enter] to continue: ";
  getline(cin, temp);
  cout << "\n\n\n";
}

//sets the data for each pokemon chosen.
void setPokemonInfo(pokemon team[], int i, int choice){
  switch(choice) {
  case 1:
    team[i].setData("Blaziken", 187, 172, 122, 132);
    team[i].setType("Fighting", "Fire");
    team[i].setMoves("Flare Blitz", "Close Combat", "Earthquake", "Swords Dance");
    team[i].setAttacks(120, 120, 100, 0);
    team[i].setMoveTypes("Fire", "Fighting", "Ground", "Normal");
    break;
  case 2:
    team[i].setData("Seperior", 182, 127, 147, 165);
    team[i].setType("Grass");
    team[i].setMoves("Leaf Storm", "Leaf Blade", "Iron Tail", "Dragon Tail");
    team[i].setAttacks(130, 90, 100, 60);
    team[i].setMoveTypes("Grass", "Grass", "Steel", "Dragon");
    break;
  case 3:
    team[i].setData("Greninja", 179, 147, 119, 174);
    team[i].setType("Water", "Dark");
    team[i].setMoves("Waterfall", "Dark Pulse", "Ice Beam", "U-turn");
    team[i].setAttacks(80, 80, 90, 70);
    team[i].setMoveTypes("Water", "Dark", "Ice", "Bug");
    break;
  case 4:
    team[i].setData("Lucario", 177, 162, 122, 142);
    team[i].setType("Fighting", "Steel");
    team[i].setMoves("Close Combat", "Flash Cannon", "Ice Punch", "Extreme Speed");
    team[i].setAttacks(120, 80, 75, 80);
    team[i].setMoveTypes("Fighting", "Steel", "Ice", "Normal");
    break;
  case 5:
    team[i].setData("Garchomp", 215, 182, 147, 154);
    team[i].setType("Dragon", "Ground");
    team[i].setMoves("Iron Tail", "Iron Head", "Dragon Claw", "Earthquake");
    team[i].setAttacks(100, 80, 80, 100);
    team[i].setMoveTypes("Steel", "Steel", "Dragon", "Ground");
    break;
  case 6:
    team[i].setData("Bisharp", 172, 177, 152, 122);
    team[i].setType("Dark", "Steel");
    team[i].setMoves("Sucker Punch", "Iron Head", "Knock Off", "Swords Dance");
    team[i].setAttacks(70, 80, 65, 0);
    team[i].setMoveTypes("Dark", "Steel", "Dark", "Normal");
    break;
  case 7:
    team[i].setData("Cinccino", 182, 147, 112, 167);
    team[i].setType("Normal");
    team[i].setMoves("Rock Blast", "Bullet Seed", "Tail Slap", "Tickle");
    team[i].setAttacks(125, 125, 125, 0);
    team[i].setMoveTypes("Ground", "Grass", "Normal", "Normal");
    break;
  case 8:
    team[i].setData("Cinderace", 187, 168, 127, 171);
    team[i].setType("Fire");
    team[i].setMoves("Pyro Ball", "High Jump Kick", "Blaze Kick", "U-turn");
    team[i].setAttacks(120, 130, 85, 70);
    team[i].setMoveTypes("Fire", "Fighting", "Fire", "Bug");
    break;
  case 9:
    team[i].setData("Pikachu", 142, 107, 92, 142);
    team[i].setType("Electric");
    team[i].setMoves("Thunderbolt", "Electro Ball", "Iron Tail", "Electroweb");
    team[i].setAttacks(90, 110, 100, 75);
    team[i].setMoveTypes("Electric", "Electric", "Steel", "Electric");
    break;
  default:
    team[i].setData("Meowstic", 181, 100, 128, 156);
    team[i].setType("Psychic");
    team[i].setMoves("Shadow Ball", "Psyshock", "Disarming Voice", "Psybeam");
    team[i].setAttacks(80, 80, 60, 65);
    team[i].setMoveTypes("Ghost", "Psychic", "Psychic", "Psychic");
  }
}

//displays your team and their hp
void displayPokemon(pokemon team[]){
  string temp;
  for (int i = 0; i < 6; i++){
    cout << i + 1 << ". "<< team[i].getName() << ": " << team[i].getHP() << " HP" <<  endl; 
  }
}

//for special moves like Tickle or Swords Dance where they affect character traits instead of hp.
void special(pokemon team[], int i, pokemon enemy[], int j){
  if (team[i].getMove4() == "Tickle"){
    enemy[j].setAttack(enemy[j].getAttack() - 10);
    enemy[j].setDefense(enemy[j].getDefense() - 10);
    cout << "It dropped the enemies attack and defense!" << endl;
  } else {
    team[i].setAttack(team[i].getAttack() + 20);
    cout << "It's attack rose!" << endl;
  }
}