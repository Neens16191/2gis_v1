

all: main.o libVoyageur.a
	g++ -o gis main.o -L. -lVoyageur

main.o:
	g++ -c 2gis_v1.cpp -o main.o

libVoyageur.a: CommisVoyageur.o
	ar rc libVoyageur.a CommisVoyageur.o

CommisVoyageur.o:
	g++ -c CommisVoyageur.cpp

clean:
	rm -f *.o gis *.a