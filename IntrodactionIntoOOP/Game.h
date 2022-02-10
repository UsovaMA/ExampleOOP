#pragma once
#include <iostream>
#include <string>

/*
1. различие между классом и структурой - возможность сокрытия информации,
контролируемый доступ - сеттеры и геттеры.
2. с чего начинается работа над классом - определение набора
классов и их полей.
2.5. вывод на экран.
3. конструкторы!!!! 3 штуки!!!
4. выделение классов: что класс, а что структура.
5. сокрытие важных данных, их обрабока в сеттерах и геттерах
6. а нужно ли наследование? - организация родительского класса
7. protected - для доступа поля родителя в потомке.
8. реализуете нужный функционал!
*/

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
    // может быть огромная проверка - можно ли так сделать
    name = _name;
  }

  void setDamage(double _damage) {
    if (_damage < 0) {
      std::cout << "FAILED!!!!" << std::endl;
      //std::logic_error("Failed!");
      damage = 0;
    }
    else
      damage = _damage;
  }

  void setStrenght(int _strenght) {
    strenght = _strenght;
  }

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

  void print_character_info() {
    std::cout << "Name: " << name << std::endl <<
      "Gender: " << gender << std::endl <<
      "Power: " << power << std::endl <<
      "Health: " << health << std::endl;
   };

  void attack(Character x);
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

class Warrior : Character {
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
    armor = 30.0;
    /* Axe a;
    weapon = a;*/
  };

  // конструктор инициализации расширенный
  Warrior(std::string _name, std::string  _gender, double _power,
  double _health, std::string _nameW, double _damage, int _strenght,
  double _armor) : Character(_name, _gender, _power, _health) {
    
    weapon.setName(_nameW);
    weapon.setDamage(_damage);
    weapon.setStrenght(_strenght);

    armor = _armor;
  };

  // конструктор инициализации
  Warrior(std::string _name, std::string  _gender, double _power,
    double _health, Axe _weapon, double _armor)
    : Character(_name, _gender, _power, _health) {
    weapon = _weapon;
    armor = _armor;
  };

  // конструктор копирования
  Warrior(const Warrior &w) : Character(w.name, w.gender, w.power, w.health) {
    weapon = w.weapon;
    armor = w.armor;
  };

  void print_character_info() {
    Character::print_character_info();
    std::cout << "Armor: " << armor << std::endl <<
      /*
      "Weapon: " << w.getName() << std::endl <<
      "Weapon's damage: " << w.getDamage() << std::endl <<
      "Weapon's strenght: " << w.getStrenght() << std::endl;
      */
      "Weapon: " << weapon.getName() << std::endl <<
      "Weapon's damage: " << weapon.getDamage() << std::endl <<
      "Weapon's strenght: " << weapon.getStrenght() << std::endl;
  };

};
