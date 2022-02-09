#include "Game.h"

void print_character_info(const Warrior *c, const Axe *w) {
  std::cout << "Name: " << c->name << std::endl <<
    "Gender: " << c->gender << std::endl <<
    "Power: " << c->power << std::endl <<
    "Health: " << c->health << std::endl <<
    "Armor: " << c->armor << std::endl <<
    "Weapon: " << w->name << std::endl <<
    "Weapon's damage: " << w->damage << std::endl <<
    "Weapon's strenght: " << w->strenght << std::endl;
}
