#include "Game.h"

int main() {
  Warrior user_0001;

  Axe user_0002_weapon("Knife", 5.0, 30);
  Warrior user_0002("Grom Hellscream", "male", 40.0, 100.0, user_0002_weapon, 30.0);

  Warrior user_0003(user_0002);

  // вызов метода для объекта класса
  user_0001.print_character_info();
  user_0002.print_character_info();
  user_0003.print_character_info();

  system("pause");
  return 0;
}