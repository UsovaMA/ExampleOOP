#pragma once

#include <iostream>
#include <string>
#include <time.h>

#define MAX_HEALTH 100
#define CRIT -1

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
  Character(std::string _name, std::string  _gender, double _power);
  Character(const Character& w);

  // методы

  void restoreHealth() {
    //health = MAX_HEALTH;
    //health = (30 + rand() % 71);
    //health += health * (30 + rand() % 71) * 0.01;
    //health = 40 + 60 * (30%-100%)
    health += (MAX_HEALTH - health) * (30 + rand() % 71) * 0.01;
  };

  bool crit() const { 
    return rand() % 100 < 3;  // теория вероятности
  };

  virtual bool attack(Character &ch) = 0;
  virtual bool attacted(double _damage) = 0;

  void print();
};

class Human : public Character {
  Gun weapon;
  int technics;

public:
  Human();
  Human(std::string _name, std::string  _gender, double _power,
    std::string _nameW, double _damage, int _cartridges,
    double _technics);
  Human(std::string _name, std::string  _gender, double _power,
    Gun _weapon, double _technics);
  Human(const Human &w);

  bool attack(Character &ch) {
    bool isDead;

    if (weapon.cartridges == 0) {
      isDead = ch.attacted(power);
    } else {
        weapon.cartridges--;
        if (crit()) {
          isDead = ch.attacted(MAX_HEALTH);
        } else {
          double damage_ = weapon.damage * (1 + technics * 0.01);
          isDead = ch.attacted(damage_);
        }
    }
    
    if (isDead) technics += 20;

    return isDead;
  };

  bool attacted(double _damage) {
    bool died;
    if (health <= _damage) {
      health = 0.0;
      died = true;
    }
    else {
      health -= _damage;
      died = false;
    }
    return died;
  };

  void print();
};

class Archer : public Character {
  Bow weapon;
  int dexterity;

public:
  Archer();
  Archer(std::string _name, std::string  _gender, double _power,
    std::string _nameW, double _damage, int _arrows, double _extraDamage,
    int _time, double _dexterity);
  Archer(std::string _name, std::string  _gender, double _power,
    Bow _weapon, double _dexterity);
  Archer(const Archer &w);

  void print();
};

class Warrior : public Character {
  Axe weapon;
  double armor;

public:
  Warrior();
  Warrior(std::string _name, std::string  _gender, double _power,
  std::string _nameW, double _damage, int _strenght,
  double _armor);
  Warrior(std::string _name, std::string  _gender, double _power,
    Axe _weapon, double _armor);
  Warrior(const Warrior &w);

  void print();
};
