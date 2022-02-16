#pragma once
#include <iostream>
#include <string>

class Weapon;
class Gun;
class Bow;
class Axe;

class Character;
class Human;
class Archer;
class Warrior;

/*************** Weapons ****************/

class Weapon {
protected:
  std::string name;
  double damage;

public:
  Weapon() {
    name = "Foo";
    damage = 0;
  };

  Weapon(std::string _name, double _damage) {
    name = _name;
    damage = _damage;
  };

  Weapon(const Weapon &w) {
    name = w.name;
    damage = w.damage;
  };

  void print() {
    std::cout << "Weapon's name: " << name << std::endl <<
      "Weapon's damage: " << damage << std::endl;
  };
};

class Gun : public Weapon {
  int cartridges;

public:
  Gun() {
    name = "PlasmaGun";
    damage = 20.0;
    cartridges = 15;
  };

  Gun(std::string _name, double _damage, int _cartridges) : Weapon(_name, _damage) {
    cartridges = _cartridges;
  };

  Gun(const Gun &a) : Weapon(a.name, a.damage) {
    cartridges = a.cartridges;
  };

  void print() {
    Weapon::print();
    std::cout << "Weapon's cartridge count: " << cartridges << std::endl;
  };

  friend class Human;     // открывает доступ к скрытым поля указанному классу
};

struct Bow : public Weapon {
  int arrows;
  double extraDamage;
  int time;

public:
  Bow() {
    name = "PlasmaGun";
    damage = 20.0;
    arrows = 10;
    extraDamage = 5.0;    // урон в секунду
    time = 5;             // в секундах
  };

  Bow(std::string _name, double _damage, int _arrows, double _extraDamage, int _time) : Weapon(_name, _damage) {
    arrows = _arrows;
    extraDamage = _extraDamage;
    time = _time;
  };

  Bow(const Bow &a) : Weapon(a.name, a.damage) {
    arrows = a.arrows;
    extraDamage = a.extraDamage;
    time = a.time;
  };

  void print() {
    Weapon::print();
    std::cout << "Weapon's arrows count: " << arrows << std::endl;
    std::cout << "Weapon's extra damage per second: " << extraDamage << std::endl;
    std::cout << "Weapon's effect time: " << time << std::endl;
  };

  friend class Archer;
};

class Axe : public Weapon{
  int strenght;

public:
  Axe() {
    name = "Gorehowl";
    damage = 30.0;
    strenght = 100.0;
  };

  Axe(std::string _name, double _damage, int _strenght) : Weapon(_name, _damage) {
    strenght = _strenght;
  };

  Axe(const Axe &a) : Weapon(a.name, a.damage) {
    strenght = a.strenght;
  };

  /*

  // Пока не требуются по реализации

  // геттер (пример)
  std::string getName() {
    return name;
  };

  // сеттер (пример)
  void setDamage(double _damage) {
    if (_damage < 0) {
      std::cout << "FAILED!!!!" << std::endl;
      //std::logic_error("Failed!");
      damage = 0;
    }
    else
      damage = _damage;
  }

  */

  void print() {
    Weapon::print();
    std::cout << "Weapon's strenght: " << strenght << std::endl;
  };

  friend class Warrior;
};

/***************** Characters ****************/

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
  Character(std::string _name, std::string  _gender, double _power, double _health) {
    name = _name;
    gender = _gender;
    power = _power;
    health = _health;
  };

  // конструктор копирования
  Character(const Character& w) {
    name = w.name;
    gender = w.gender;
    power = w.power;
    health = w.health;
  };

  void print() {
    std::cout << "Name: " << name << std::endl <<
      "Gender: " << gender << std::endl <<
      "Power: " << power << std::endl <<
      "Health: " << health << std::endl;
   };
};

class Human : Character {
  Gun weapon;
  int technics;

public:
  Human() {
    name = "James Bond";
    gender = "male";
    power = 10.0;
    health = 100.0;
    // + оружие по умолчанию создаётся само
    technics = 30.0;
  };

  Human(std::string _name, std::string  _gender, double _power,
    double _health, std::string _nameW, double _damage, int _cartridges,
    double _technics) : Character(_name, _gender, _power, _health) {
    weapon.name = _nameW;
    weapon.damage = _damage;
    weapon.cartridges = _cartridges;
    technics = _technics;
  };

  Human(std::string _name, std::string  _gender, double _power,
    double _health, Gun _weapon, double _technics)
    : Character(_name, _gender, _power, _health) {
    weapon = _weapon;
    technics = _technics;
  };

  Human(const Human &w) : Character(w.name, w.gender, w.power, w.health) {
    weapon = w.weapon;
    technics = w.technics;
  };

  void print() {
    Character::print();
    std::cout << "Technics: " << technics << std::endl;
    weapon.print();
  };
};

class Archer : Character {
  Bow weapon;
  int dexterity;

public:
  Archer() {
    name = "Legolas";
    gender = "male";
    power = 0.0;
    health = 100.0;
    dexterity = 15.0;
  };

  Archer(std::string _name, std::string  _gender, double _power,
    double _health, std::string _nameW, double _damage, int _arrows, double _extraDamage,
    int _time, double _dexterity) : Character(_name, _gender, _power, _health) {

    weapon.name = _nameW;
    weapon.damage = _damage;
    weapon.arrows = _arrows;
    weapon.extraDamage = _extraDamage;
    weapon.time = _time;

    dexterity = _dexterity;
  };

  Archer(std::string _name, std::string  _gender, double _power,
    double _health, Bow _weapon, double _dexterity)
    : Character(_name, _gender, _power, _health) {
    weapon = _weapon;
    dexterity = _dexterity;
  };

  Archer(const Archer &w) : Character(w.name, w.gender, w.power, w.health) {
    weapon = w.weapon;
    dexterity = w.dexterity;
  };

  void print() {
    Character::print();
    std::cout << "Dexterity: " << dexterity << std::endl;
    weapon.print();
  };
};

class Warrior : Character {
  Axe weapon;
  double armor;

public:
  Warrior() {
    name = "Garrosh Hellscream";
    gender = "male";
    power = 10.0;
    health = 100.0;
    armor = 30.0;
  };

  // конструктор инициализации (расширенный)
  Warrior(std::string _name, std::string  _gender, double _power,
  double _health, std::string _nameW, double _damage, int _strenght,
  double _armor) : Character(_name, _gender, _power, _health) {
    
    weapon.name = _nameW;
    weapon.damage = _damage;
    weapon.strenght = _strenght;

    armor = _armor;
  };

  Warrior(std::string _name, std::string  _gender, double _power,
    double _health, Axe _weapon, double _armor)
    : Character(_name, _gender, _power, _health) {
    weapon = _weapon;
    armor = _armor;
  };

  Warrior(const Warrior &w) : Character(w.name, w.gender, w.power, w.health) {
    weapon = w.weapon;
    armor = w.armor;
  };

  void print() {
    Character::print();
    std::cout << "Armor: " << armor << std::endl;
    weapon.print();
  };

};
