#pragma once
#include <iostream>
#include <string>

// Weapons

struct Gun {
  std::string name;
  double damage;
  int cartridges;
};

struct Bow {
  std::string name;
  double damage;
  int arrows;
  double extraDamage;
  int time;
};

struct Axe {
  std::string name;
  double damage;
  int strenght;
};

// Characters

struct Human {
  std::string name;
  std::string  gender;
  double power;
  double health;
  // оружие???
  int technics;
};

struct Archer {
  std::string name;
  std::string  gender;
  double power;
  double health;
  // оружие???
  int dexterity;
};

struct Warrior {
  std::string name;
  std::string  gender;
  double power;
  double health;
  // оружие???
  double armor;
};

void print_character_info(const Warrior *c, const Axe *w);