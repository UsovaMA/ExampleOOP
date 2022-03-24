#pragma once

class CPoint {
  int x;
  int y;
public:
  CPoint() : x(0), y(0) { };
  CPoint(int _x, int _y) : x(_x), y(_y) { };

  friend class CTrapezoid;
};

class CTrapezoid {
  CPoint A;
  CPoint B;
  CPoint C;
  CPoint D;
public:
  CTrapezoid(CPoint _A, CPoint _B, CPoint _C, CPoint _D) {
    A.x = _A.x;
    A.y = _A.y;
    B.x = _B.x;
    B.y = _B.y;
    C.x = _C.x;
    C.y = _C.y;
  };

  bool checkExist() { return false; };

  float calculateAB();
  float calculateBC();
  float calculateCD();
  float calculateAD();

  float* calculateSides();

  float calculateP();
  float calculateS();
};