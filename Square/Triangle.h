#pragma once
#include <cmath>

class CPoint {
  int x;
  int y;
 public:
   CPoint() : x(0), y(0) { };
   CPoint(int _x, int _y) : x(_x), y(_y) {};
  friend class CTriangle;
};

class CTriangle {
  CPoint A;
  CPoint B;
  CPoint C;
public:
  CTriangle(CPoint _A, CPoint _B, CPoint _C) {
    A.x = _A.x;
    B.x = _B.x;
    C.x = _C.x;
    A.y = _A.y;
    B.y = _B.y;
    C.y = _C.y;
  };

  float calculateAB() { return sqrt(pow(A.x - B.x, 2)+ pow(A.y - B.y, 2)); };
  float calculateBC() { return sqrt(pow(C.x - B.x, 2) + pow(C.y - B.y, 2)); };
  float calculateAC() { return sqrt(pow(A.x - C.x, 2) + pow(A.y - C.y, 2)); };

  float* calculateSides() {
    float* sides = new float[3];
    sides[0] = calculateAB();
    sides[1] = calculateBC();
    sides[2] = calculateAC();
    return sides;
  };

  float calculateP() {
    float* sides = new float[3];
    sides = calculateSides();
    return sides[0] + sides[1] + sides[2];
  };

  float calculateS() {
    float* sides = new float[3];
    sides = calculateSides();
    float p = (sides[0] + sides[1] + sides[2]) * 0.5;
    return sqrt(p * (p - sides[0]) * (p - sides[1]) * (p - sides[2]));
  };
};
