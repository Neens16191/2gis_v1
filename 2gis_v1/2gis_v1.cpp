#include <string.h>

#include <fstream>
#include <sstream>

#include "CommisVoyageur.h"

#define HELPINFO \
  "\nYou have called up additional information about the program. \n\
This program is designed to fulfill the company's test task 2 gis from September 2021.\
The program is designed exclusively for educational purposes. \nAbout the program : \n\
-f [file] - specify the file[file] from which the transition matrix will be read. \n\
-m - choose a way to solve the traveling salesman problem. \n\
-h - opening a window with information.\n\n \
Mikhail Tsarev 2022\n\n"

int reader(int argc, char* argv[], int* N, int matrix[26][26], char method[15],
    int* printinfo) {
    int i = 1;
    while (i < argc) {
        if (!strcmp(argv[i], "-f")) {
            int k = 0, j = 0;
            std::string line, item;
            std::ifstream in;
            in.open(argv[i + 1]);

            while (getline(in, line)) {
                j = 0;
                std::stringstream ss;
                ss.str(line);
                char delim = ' ';
                while (getline(ss, item, delim)) {
                    matrix[k][j] = stoi(item);
                    j++;
                }
                k++;
            }
            *N = j;
        }
        else if (!strcmp(argv[i], "-m")) {
            for (int k = 0; k < 14 && argv[i + 1][k] != '\0'; k++) {
                method[k] = argv[i + 1][k];
                method[k + 1] = '\0';
            }
        }
        else if (!strcmp(argv[i], "-h")) {
            printf(HELPINFO);
            *printinfo = 1;
            i--;
        }
        i += 2;
    }
    return 0;
}

int worker(int matrix[26][26], char* method, int N, int printinfo) {
    int* way, cost;
    // Проверка, что выбран метод и матрица записана
    if (matrix[0][0] != -1 && strcmp(method, "\0")) {
        Voyageur voyageur(matrix, N);

        if (!strcmp(method, "np_complete")) {
            printf("Using full search method\n");
            voyageur.Recursive_Complete(0, 0);  // Запуск метода полного перебора
        }
        else if (!strcmp(method, "np_partial")) {
            printf("Using greedy algorithm\n");
            voyageur.Partial();  // Запуск жадного алгоритма
        }
        else {
            printf(
                "Error: Unable to process this method :(\n");  // Вывод ошибку, если
                                                               // метод определить не
                                                               // удалось
        }
        way = voyageur.getWay();
        cost = voyageur.getTotalCost();
        if (cost > 0) {
            std::cout << "Way: ";
            for (int index = 0; index < N; index++) {
                printf("%c ", way[index] + 65);
            }
            std::cout << std::endl << "Total cost for way = " << cost << std::endl;
        }
        else {
            std::cout << "Failed to calculate path\n";
        }
    }
    else if (!printinfo) {
        std::cout << "Wrong input data\n";
    }
    return 0;
}

int main(int argc, char* argv[]) {
    int N, matrix[26][26] = { {-1}, {-1} }, printinfo = 0;
    char method[15] = "\0";
    reader(argc, argv, &N, matrix, method, &printinfo);
    worker(matrix, method, N, printinfo);
    return 0;
}