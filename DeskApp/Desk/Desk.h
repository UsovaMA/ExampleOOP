#pragma once
#include <iostream>
#include <string>

/*
 * �������� �� ��������� ������� (c������� ����������� ���������� + ������� � �����������):
 *
 * 1. Desk - �������� - ��� ������������ -> ����������� ����������
 * 2. App - ������ - �������� ������ �� Desk
 * 3. App - �������� - ��� ������������, ��� ��������� - �/�++, �����, �������� ���������� ������
      -> ���� �� Desk.h
 */

class Product {
  std::string code;
  std::string name;
  int price;
  int discount;
  int count;
public:
  // ������������
  Product();
  Product(std::string _code, std::string _name, int _price, int _discount, int _count);

  // ������

  // ����������
  bool operator==(const Product& prod);
  friend std::ostream& operator<< (std::ostream& out, const Product& prod);

  friend class Busket;
};

class Assortment {
  Product* all;
  int count;

public:
  // ����������� - �� ��������� ������ �� �����
  Assortment();
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
