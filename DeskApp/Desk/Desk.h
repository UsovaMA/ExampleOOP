#pragma once
#include <iostream>
#include <string>
#include <fstream>

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
  Product() {};
  Product(std::string _code, std::string _name, int _price, int _discount, int _count);

  // методы

  // перегрузки
  bool operator==(const Product& prod);
  friend std::ostream& operator<< (std::ostream& out, const Product& prod);

  friend class Busket;
  friend class Assortment;
};

class Assortment {
public:
  Product* all;
  int count;

  // конструктор - по умолчанию читаем из файла
  Assortment() {
    std::string line;
    std::ifstream in("..\\source\\assortment.txt"); // окрываем файл для чтения
    if (in.is_open()) {
      getline(in, line);
      count = atoi(line.c_str());
      all = new Product[count];
      int i = 0;
      while (getline(in, line)) {
        all[i].code = getWord(&line);
        all[i].name = getWord(&line);
        all[i].price = atoi(getWord(&line).c_str());
        all[i].discount = 20 + rand() % 31;
        all[i].count = atoi(getWord(&line).c_str());
        i++;
      }
    }

    in.close();     // закрываем файл
  };

  std::string getProductName(int i) {
    return all[i].name;
  }

private:
  std::string getWord(std::string* line) {
    std::string delimiter = " : ";
    int pos = line->find(delimiter);
    std::string token = line->substr(0, pos);
    line->erase(0, pos + delimiter.length());
    return token;
  }
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
