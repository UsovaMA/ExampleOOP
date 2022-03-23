#pragma once
#include <iostream>
#include <string>
#include <fstream>

/*
 * �������� �� ��������� ������� (c������� ����������� ���������� + ������� � �����������):
 *
 * 1. Desk - �������� - ��� ������������ -> ����������� ����������
 * 2. App - ������ - �������� ������ �� Desk
 * 3. App - �������� - ��� ������������, ��� ��������� - �/�++, �����, �������� ���������� ������
 *    -> ���� �� Desk.h
 *
 * � ������� ������ �������:
 *   1. ������ ������ ������� � ���������� ������ (App) � ����������� ����������� Desk,
 *   2. ����������� �������� ����������� ����������,
 *   3. ������ ����������� ��� ������,
 *   4. ����������� �������� "����" ������������.
 */

class Product {
  std::string code;
  std::string name;
  int price;
  int discount;
  int count;
public:
  // ������������
  Product() {};
  Product(std::string _code, std::string _name, int _price, int _discount, int _count);

  // ������

  // ����������
  bool operator==(const Product& prod);
  friend std::ostream& operator<< (std::ostream& out, const Product& prod);

  friend class Busket;
  friend class Assortment;
};

class Assortment {
public:
  Product* all;
  int count;

  // ����������� - �� ��������� ������ �� �����
  Assortment() {
    std::string line;
    std::ifstream in("..\\source\\assortment.txt"); // �������� ���� ��� ������
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

    in.close();     // ��������� ����
  };

  std::string getProductName(int i) {
    return all[i].name;
  };

  int getCount() {
    return count;
  };

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
  // ����������� - �� ��������� ������ �������
  Busket();

  // ����������
  ~Busket();

  // ������
  void scan(std::string _code);
  void showLastProduct();
  void addToCheck();
  std::string makeCheck();
  int calculateTotalCost();

private: // ������ ����� ������� �������� (����������)
  // ���� ���� ������������ �� ���������� ����� ������������� ���
};
