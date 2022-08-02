# 2gis_v1
Первый вариант тестового задания от компании 2gis от сентября 2021

### Приветствую в моем тестовом проекте от компании 2gis!

В ветке `develop` находится написанная для ОС linux версия задачи. Сам разработанный код в обоих ветках совпадает, однако в этой ветке отсутствуют файлы Visual Studio и добавлен Makefile для удобной сборки проекта.

---

### Задача коммивояжёра
В тестовом задании мне предлоглось разработать программу решающую задачу коммивояжера методом полного перебора, а также любым эвристическим алгоритмом на мой выбор (я реализлвал жадный алгоритм). Задача коммивояжёра заключается в поиске самого выгодного маршрута, проходящего через указанные города не более одного раза. Сами задачи в различных источниках варьируются, в каких-то необходимо обойти все города без учета стартового и конечного, в других задается стартовых город, однако требуется обойти все корода по одному разу без указания завершающего, в третьих необходдимо обойти все города и вернуться в стартовый. Мною был выбран вариант с задачей стартового города, но без обозначения последного (хотя его, как мне кажется, не трудно переделать под вариант 3, с возвращением в стартовый город, ответьте письмом на почту, если захотите увидеть такой вариант). Программа в результате работы выводит путь, пройденный комиивояжером в виде целого действительного числа и порядок его следования (он выводится в виде заглавных латинских букв, где первым городом под буквой "A" будет город пути из которого заданы в первой строке матрицы, город "B" - город пути из которого обозначены во второй строке и так далее).

Пример вывода программы:

`
  Using full search method
  
  Way: A D E B C F 
  
  Total cost for way = 79
`

В первой строке выводится метод, который используется для поиска пути, во второй порядок следования городов, в третьей затраты на перемещения по пути. (матрица для вывода данного результата находтся в файле "matr3.txt")

Входные данные представляют из себя строку с запуском программы, куда при помощи флагов подается файл с матрицей расстояний (-f [file]), метод нахождения оптимального пути (-m [method]) или попросим программу вывести информацию о себе (-h).

Пример: `./gis -f matr3.txt -m np_complete`
