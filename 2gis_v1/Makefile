all: clean main.o libVoyageur.a
	g++ -o gis main.o -L. -lVoyageur

main.o:
	g++ -c 2gis_v1.cpp -o main.o

libVoyageur.a: CommisVoyageur.o
	ar rc libVoyageur.a CommisVoyageur.o

CommisVoyageur.o:
	g++ -c CommisVoyageur.cpp

tests: gis
	@echo "Первый тест с полным перебором"
	./gis -f matr.txt -m np_complete
	@echo "\nПервый тест с жадным алгоритмом"
	./gis -f matr.txt -m np_partial
	@echo "\n\nВторой тест с полным перебором"
	./gis -f matr2.txt -m np_complete
	@echo "\nВторой тест с жадным алгоритмом"
	./gis -f matr2.txt -m np_partial
	@echo "\n\nТретий тест с полным перебором"
	./gis -f matr3.txt -m np_complete
	@echo "\nТретий тест с жадным алгоритмом"
	./gis -f matr3.txt -m np_partial
	@echo "\n\nСерия тестов на неправильные данные"
	./gis -f mat.txt -m np_complete
	./gis -f matr5.txt -m np_complete
	./gis -f matrix.txt -m np_complete
	./gis -m np_complete
	./gis -f mat.txt
	@echo "\n\nВывод информации"
	./gis -h

clean:
	rm -f *.o gis *.a