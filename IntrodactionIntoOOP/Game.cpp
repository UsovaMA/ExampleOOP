#include "Game.h"

/************************ WEAPON'S CLASSES REALIZATION ******************************/

Weapon::Weapon() {
  name = "Foo";
  damage = 0;
}

Weapon::Weapon(std::string _name, double _damage) {
  name = _name;
  damage = _damage;
}

Weapon::Weapon(const Weapon &w) {
  name = w.name;
  damage = w.damage;
}

void Weapon::print() {
  std::cout << "Weapon's name: " << name << std::endl <<
    "Weapon's damage: " << damage << std::endl;
}

/************************************************************************************/

Gun::Gun() {
  name = "PlasmaGun";
  damage = 20.0;
  cartridges = 15;
}

Gun::Gun(std::string _name, double _damage, int _cartridges) : Weapon(_name, _damage) {
  cartridges = _cartridges;
}

Gun::Gun(const Gun &a) : Weapon(a.name, a.damage) {
  cartridges = a.cartridges;
}

void Gun::print() {
  Weapon::print();
  std::cout << "Weapon's cartridge count: " << cartridges << std::endl;
}

/************************************************************************************/

Bow::Bow() {
  name = "PlasmaGun";
  damage = 20.0;
  arrows = 10;
  extraDamage = 5.0;    // урон в секунду
  time = 5;             // в секундах
}

Bow::Bow(std::string _name, double _damage, int _arrows, double _extraDamage, int _time) : Weapon(_name, _damage) {
  arrows = _arrows;
  extraDamage = _extraDamage;
  time = _time;
}

Bow::Bow(const Bow &a) : Weapon(a.name, a.damage) {
  arrows = a.arrows;
  extraDamage = a.extraDamage;
  time = a.time;
}

void Bow::print() {
  Weapon::print();
  std::cout << "Weapon's arrows count: " << arrows << std::endl;
  std::cout << "Weapon's extra damage per second: " << extraDamage << std::endl;
  std::cout << "Weapon's effect time: " << time << std::endl;
}

/************************************************************************************/

Axe::Axe() {
  name = "Gorehowl";
  damage = 30.0;
  strenght = 100.0;
}

Axe::Axe(std::string _name, double _damage, int _strenght) : Weapon(_name, _damage) {
  strenght = _strenght;
}

Axe::Axe(const Axe &a) : Weapon(a.name, a.damage) {
  strenght = a.strenght;
}

void Axe::print() {
  Weapon::print();
  std::cout << "Weapon's strenght: " << strenght << std::endl;
}

/************************ CHARACTER'S CLASSES REALIZATION ***************************/

// конструктор по умолчанию
Character::Character() {
  name = "Bob";
  gender = "male";
  power = 1.0;
  health = MAX_HEALTH;
}

// конструктор инициализации
Character::Character(std::string _name, std::string  _gender, double _power) {
  name = _name;
  gender = _gender;
  power = _power;
  health = MAX_HEALTH;
}

// конструктор копирования
Character::Character(const Character& w) {
  name = w.name;
  gender = w.gender;
  power = w.power;
  health = MAX_HEALTH;
}

void Character::print() {
  std::cout << "Name: " << name << std::endl <<
    "Gender: " << gender << std::endl <<
    "Power: " << power << std::endl <<
    "Health: " << health << std::endl;
}

/************************************************************************************/

Human::Human() {
  name = "James Bond";
  gender = "male";
  power = 10.0;
  health = MAX_HEALTH;
  technics = 30.0;
}

Human::Human(std::string _name, std::string  _gender, double _power,
  std::string _nameW, double _damage, int _cartridges,
  double _technics) : Character(_name, _gender, _power) {
  weapon.name = _nameW;
  weapon.damage = _damage;
  weapon.cartridges = _cartridges;
  technics = _technics;
}

Human::Human(std::string _name, std::string  _gender, double _power,
  Gun _weapon, double _technics)
  : Character(_name, _gender, _power) {
  weapon = _weapon;
  technics = _technics;
}

Human::Human(const Human &w) : Character(w.name, w.gender, w.power) {
  weapon = w.weapon;
  technics = w.technics;
}

void Human::print() {
  Character::print();
  std::cout << "Technics: " << technics << std::endl;
  weapon.print();
}

/************************************************************************************/

Archer::Archer() {
  name = "Legolas";
  gender = "male";
  power = 0.0;
  health = MAX_HEALTH;
  dexterity = 15.0;
}

Archer::Archer(std::string _name, std::string  _gender, double _power,
  std::string _nameW, double _damage, int _arrows, double _extraDamage,
  int _time, double _dexterity) : Character(_name, _gender, _power) {

  weapon.name = _nameW;
  weapon.damage = _damage;
  weapon.arrows = _arrows;
  weapon.extraDamage = _extraDamage;
  weapon.time = _time;

  dexterity = _dexterity;
}

Archer::Archer(std::string _name, std::string  _gender, double _power,
  Bow _weapon, double _dexterity)
  : Character(_name, _gender, _power) {
  weapon = _weapon;
  dexterity = _dexterity;
}

Archer::Archer(const Archer &w) : Character(w.name, w.gender, w.power) {
  weapon = w.weapon;
  dexterity = w.dexterity;
}

void Archer::print() {
  Character::print();
  std::cout << "Dexterity: " << dexterity << std::endl;
  weapon.print();
}

/************************************************************************************/

Warrior::Warrior() {
  name = "Garrosh Hellscream";
  gender = "male";
  power = 10.0;
  health = MAX_HEALTH;
  armor = 30.0;
}

// конструктор инициализации (расширенный)
Warrior::Warrior(std::string _name, std::string  _gender, double _power,
  std::string _nameW, double _damage, int _strenght,
  double _armor) : Character(_name, _gender, _power) {

  weapon.name = _nameW;
  weapon.damage = _damage;
  weapon.strenght = _strenght;

  armor = _armor;
}

Warrior::Warrior(std::string _name, std::string  _gender, double _power,
  Axe _weapon, double _armor)
  : Character(_name, _gender, _power) {
  weapon = _weapon;
  armor = _armor;
}

Warrior::Warrior(const Warrior &w) : Character(w.name, w.gender, w.power) {
  weapon = w.weapon;
  armor = w.armor;
}

void Warrior::print() {
  Character::print();
  std::cout << "Armor: " << armor << std::endl;
  weapon.print();
}
