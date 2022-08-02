#include "CommisVoyageur.h"
#include <fstream>
#include <string>
#include <sstream>

#define HELPINFO "\nYou have called up additional information about the program. \n\
This program is designed to fulfill the company's test task 2 gis from September 2021.\
The program is designed exclusively for educational purposes. \nAbout the program : \n\
-f [file] - specify the file[file] from which the transition matrix will be read. \n\
-m - choose a way to solve the traveling salesman problem. \n\
-h - opening a window with information.\n\n \
Mikhail Tsarev 2022\n\n"

int main(int argc, char* argv[])
{
	int N, matrix[26][26], i = 1, cost, *way;
	while (i < argc)
	{
		if (!strcmp(argv[i], "-f")) {
			int k = 0, j = 0;
			std::string line, item;
			std::ifstream in;
			in.open("matr.txt");

			while (getline(in, line))
			{
				j = 0;
				std::stringstream ss;
				ss.str(line);
				char delim = ' ';
				while (getline(ss, item, delim))
				{
					matrix[k][j] = stoi(item);
					j++;
				}
				k++;
			}
			N = j;
		}
		else if (!strcmp(argv[i], "-m")) {
			Voyageur voyageur(matrix, N);

			if (!strcmp(argv[i + 1], "np_complete")) {
				printf_s("Using full search method\n");
				voyageur.Recursive_Complete(0, 0);
			}
			else if (!strcmp(argv[i + 1], "np_partial")) {
				printf_s("Using greedy algorithm\n");
				voyageur.Partial();
			}
			else {
				printf_s("Error: Unable to process this method :(\n");
			}

			way = voyageur.getWay();
			cost = voyageur.getTotalCost();

			if (cost > 0) {
				std::cout << "Way: ";
				for (int index = 0; index < N; index++) { printf("%c ", way[index] + 65); }
				std::cout << std::endl << "Total cost for way = " << cost << std::endl;
			}

		}
		else if (!strcmp(argv[i], "-h")) {
			printf_s(HELPINFO);
			i--;
		}
		i += 2;
	}
	return 0;
}
