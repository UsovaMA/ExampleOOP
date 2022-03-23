#pragma once
#include <iostream>
#include <string>

/*
 * Указания по настройке проекта (cоздание статической библиотеки + подхват её приложением):
 *
 * 1. Desk - свойства - тип конфигурации -> статическая библиотека
 * 2. App - ссылки - добавить ссылку на Desk
 * 3. App - свойства - все конфигурации, все платформы - С/С++, общие, каталоги включаемых файлов
      -> путь до Desk.h
 */

class Product {
  std::string code;
  std::string name;
  int price;
  int discount;
  int count;
public:
  // конструкторы
  Product();
  Product(std::string _code, std::string _name, int _price, int _discount, int _count);

  // методы

  // перегрузки
  bool operator==(const Product& prod);
  friend std::ostream& operator<< (std::ostream& out, const Product& prod);

  friend class Busket;
};

class Assortment {
  Product* all;
  int count;

public:
  // конструктор - по умолчанию читаем из файла
  Assortment();
};

typedef Product* ProductLink;

class Busket {
  ProductLink* goods;
  int size;
  int count;
  ProductLink last;

public:
  // конструктор - по умолчанию пустая корзина
  Busket();

  // деструктор
  ~Busket();

  // методы
  void scan(std::string _code);
  void showLastProduct();
  void addToCheck();
  std::string makeCheck();
  int calculateTotalCost();

private: // делаем часть методов скрытыми (служебными)
  // этот блок отвественный за реализацию может прорабатывать сам
};
