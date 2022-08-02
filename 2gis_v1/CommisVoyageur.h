#pragma once

#include <iostream>

class Voyageur {
 private:
  int matrix[26][26] = {{0}, {0}};
  int N, totalCost = 0, way[26] = {-1}, tempCost = 0, tempWay[26] = {-1};

 public:
  int Recursive_Complete(int knot, int iter);
  int Partial();
  bool minWayToUnusedElem(int target, int str_number);

  Voyageur(int startMatrix[26][26], int NCount);

  int* getWay() { return way; };
  int getTotalCost() { return totalCost; };
};