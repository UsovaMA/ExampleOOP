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

class Axe {
  std::string name;
  double damage;
  int strenght;
 
public:
  Axe() {
    name = "Gorehowl";
    damage = 30.0;
    strenght = 100.0;
  };

  Axe(std::string _name, double _damage, int _strenght) {
    name = _name;
    damage = _damage;
    strenght = _strenght;
  };

  Axe(const Axe &a) {
    name = a.name;
    damage = a.damage;
    strenght = a.strenght;
  };

  // геттеры
  std::string getName() {
    return name;
  };

  double getDamage() {
    return damage;
  };

  int getStrenght() {
    return strenght;
  };

  // сеттер
  void setName(std::string _name) {
    name = _name;
  };

};

// Characters

class Character {
protected:
  std::string name;
  std::string  gender;
  double power;
  double health;

public:
  // конструктор по умолчанию
  Character() {
    name = "Bob";
    gender = "male";
    power = 1.0;
    health = 100.0;
  };

  // конструктор инициализации
  Character(std::string _name, std::string _gender, double _power, double _health) {
    name = _name;
    gender = _gender;
    power = _power;
    health = _health;
  };

  // конструктор копирования - по адресу!!!!!
  Character(const Character& c) {
    name = c.name;
    gender = c.gender;
    power = c.power;
    health = c.health;
  };

  void print_character_info() {
    std::cout << "Name: " << name << std::endl <<
      "Gender: " << gender << std::endl <<
      "Power: " << power << std::endl <<
      "Health: " << health << std::endl;
  };
};

struct Human {
  std::string name;
  std::string  gender;
  double power;
  double health;
  Gun weapon;
  int technics;
};

struct Archer {
  std::string name;
  std::string  gender;
  double power;
  double health;
  Bow weapon;
  int dexterity;
};

class Warrior : public Character {
private:
  Axe weapon;
  double armor;

public:
  // конструктор по умолчанию
  Warrior() {
    name = "Garrosh Hellscream";
    gender = "male";
    power = 10.0;
    health = 100.0;
    //Axe _weapon;
    //weapon = _weapon;
    armor = 30.0;
  };

  // конструктор инициализации
  Warrior(std::string _name, std::string _gender, double _power, double _health, Axe _weapon, double _armor)
  : Character::Character(_name, _gender, _power, _health) {
    weapon = _weapon;
    armor = _armor;
  };

  // конструктор копирования - по адресу!!!!!
  Warrior(const Warrior& w) : Character::Character(w.name, w.gender, w.power, w.health) {
    weapon = w.weapon;
    armor = w.armor;
  };

  void print_character_info() {
    Character::print_character_info();
    std::cout << "Armor: " << armor << std::endl <<
      "Weapon: " << weapon.getName() << std::endl <<
      "Weapon's damage: " << weapon.getDamage() << std::endl <<
      "Weapon's strenght: " << weapon.getStrenght() << std::endl;
  };

};
