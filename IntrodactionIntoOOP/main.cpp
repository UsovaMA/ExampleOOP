#include "Game.h"

int main() {
  Warrior user_0001;
  user_0001.name = "Garrosh Hellscream";
  user_0001.gender = "male";
  user_0001.power = 10.0;
  user_0001.health = 100.0;
  user_0001.armor = 30.0;

  Axe user_0001_weapon;
  user_0001_weapon.name = "Gorehowl";
  user_0001_weapon.damage = 30.0;
  user_0001_weapon.strenght = 100.0;

  print_character_info(&user_0001, &user_0001_weapon);

  system("pause");
  return 0;
}