#include "CommisVoyageur.h"

int findInMass(int target, int* mass, std::size_t size)
{
	std::size_t i = 0;
	for (; i < size && target != mass[i]; i++);
	return target == mass[i];
}

int Voyageur::Recursive_Complete(int knot, int iter) {
	int answer = 1;
	tempWay[iter] = knot;
	int i = 0;
	if (iter == N - 1) {
		if ((totalCost > tempCost || totalCost == 0)) {
			totalCost = tempCost;
			answer = 0;
			for (std::size_t i = 0; i < N; i++) way[i] = tempWay[i];
		}
	}
	else {
		while (i < N) {
			while (i < N && findInMass(i, tempWay, N)) {
				i++;
			}
			if (i < N && matrix[knot][i] > 0) {
				answer = 0;
				tempCost += matrix[knot][i];
				Recursive_Complete(i, iter + 1);
				tempCost -= matrix[knot][i];
				tempWay[iter + 1] = -1;
			}
			i++;
		}
	}
	return answer;
}

int Voyageur::Partial() {
  way[0] = 0;
  for (int iter = 0, i = 0; iter < N; iter++) {
    for (int j = 1; j < N; j++) {
      if (i != j) {
        if (!findInMass(j, way, N) && minWayToUnusedElem(matrix[i][j], i)) {
          way[iter + 1] = j;
          tempCost += matrix[i][j];
          i = j;
          break;
        }
      }
    }
  }
  totalCost = tempCost;
  return 0;
}

bool Voyageur::minWayToUnusedElem(int target, int str_number) {
  for (int i = 0; i < N; i++) {
    if (matrix[str_number][i] > 0 && matrix[str_number][i] < target &&
        !findInMass(i, way, N))
      return false;
  }
  return true;
}

Voyageur::Voyageur(int startMatrix[26][26], int NCount)
{
	N = NCount;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			matrix[i][j] = startMatrix[i][j];
		}
	}
}
