#pragma once

#include <iostream>
#include <string>

/******************************** WEAPON'S CLASSES **********************************/

class Weapon {
protected:
  std::string name;
  double damage;

public:
  // конструкторы
  Weapon();
  Weapon(std::string _name, double _damage);
  Weapon(const Weapon &w);

  // методы
  void print();
};

class Gun : public Weapon {
  int cartridges;

public:
  Gun();
  Gun(std::string _name, double _damage, int _cartridges);
  Gun(const Gun &a);

  void print();

  friend class Human;     // открывает доступ к скрытым поля указанному классу
};

struct Bow : public Weapon {
  int arrows;
  double extraDamage;
  int time;

public:
  Bow();
  Bow(std::string _name, double _damage, int _arrows, double _extraDamage, int _time);
  Bow(const Bow &a);

  void print();

  friend class Archer;
};

class Axe : public Weapon {
  int strenght;

public:
  Axe();
  Axe(std::string _name, double _damage, int _strenght);
  Axe(const Axe &a);

  void print();

  friend class Warrior;
};

/******************************* CHARACTERS'S CLASSES *******************************/

class Character {
protected:
  std::string name;
  std::string  gender;
  double power;
  double health;

public:
  // конструкторы
  Character();
  Character(std::string _name, std::string  _gender, double _power, double _health);
  Character(const Character& w);

  // методы
  void print();
};

class Human : Character {
  Gun weapon;
  int technics;

public:
  Human();
  Human(std::string _name, std::string  _gender, double _power,
    double _health, std::string _nameW, double _damage, int _cartridges,
    double _technics);
  Human(std::string _name, std::string  _gender, double _power,
    double _health, Gun _weapon, double _technics);
  Human(const Human &w);

  void print();
};

class Archer : Character {
  Bow weapon;
  int dexterity;

public:
  Archer();
  Archer(std::string _name, std::string  _gender, double _power,
    double _health, std::string _nameW, double _damage, int _arrows, double _extraDamage,
    int _time, double _dexterity);
  Archer(std::string _name, std::string  _gender, double _power,
    double _health, Bow _weapon, double _dexterity);
  Archer(const Archer &w);

  void print();
};

class Warrior : Character {
  Axe weapon;
  double armor;

public:
  Warrior();
  Warrior(std::string _name, std::string  _gender, double _power,
  double _health, std::string _nameW, double _damage, int _strenght,
  double _armor);
  Warrior(std::string _name, std::string  _gender, double _power,
    double _health, Axe _weapon, double _armor);
  Warrior(const Warrior &w);

  void print();
};
