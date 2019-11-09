//18.10.2019

/*Пошук у ширину
Вашим завданням буде реалізувати алгоритм пошуку в ширину для заданого
орієнтованого графу та стартової вершини s.Результатом роботи алгоритму повинна
бути довжина шляху(кількість ребер, яку треба пройти) від вершини s до
найвіддаленішої вершини(яку все ж таки можна досягти з вершини s).

Вхідні дані :
Перший рядок містить числа N - кількість ребер та s - початкову вершину.
Наступні N рядків містять пари вершин, що з’єднані між собою ребром.
Вихідні дані :
Довжина шляху до найвіддаленішої вершини.
Обмеження :
	0 < N <= 10000
	Приклади:
In:
	8 5
	0 3
	1 4
	4 2
	5 0
	5 4
	5 1
	1 2
	3 1



Out:
2
(Усі вершини можна досягнути за 1 або два кроки)
In :
	18 10
	2 9
	7 8
	4 0
	10 8
	10 4
	4 3
	1 11
	2 5
	8 2
	10 6
	3 0
	1 6
	3 11
	4 6
	0 11
	5 1
	9 0
	11 4
	Out:
4
(Найдовшим з вершини 10 є шлях до вершини 1)
In :
	https ://docs.google.com/document/d/1Bny6UTAn9E45XJm6tJYrNxE9sPGyN0qfAinFCkFm-
	Out :
11*/

#include "graph.h"
int main()
{
	int countEdges, startVertex;
	map <int, vector<int>> list;
	map <int, Vertex> vertexes;
	//char fileName[30] = "graph.txt";
	char fileName[300] = "D:\\Internet of Things\\Semestr #3\\Algorithms\\Lab_3\\bfs_example_3.txt";
	readWithFile(fileName, list, countEdges, startVertex);
	printf("Adjacency list:\n");
	printAdjacencyList(list);
	printf("\nCount vertex : %d\n", list.size());
	printf("Count edges : %d\n", countEdges);
	printf("Start vertex : %d\n\n", startVertex);
	int maxLenght = BFS(list, vertexes, startVertex);
	printf("Result :\n");
	printf("vertex, |lenght, visited\n");
	for (auto i : vertexes) {
		printf("%4d\t|%4d\t   %-5s\n", 
			i.first, vertexes[i.first].lenghtFromStart, 
			vertexes[i.first].isVisited == true? "yes":"no");
	}
	cout << "\nMax lenght = " << maxLenght << endl;
	for (auto it : vertexes) {
		if (vertexes[it.first].lenghtFromStart == maxLenght) {
			cout << "Vertex : " << it.first << endl;
			cout << "Path from start vertex : ";
			int key = it.first;
			printPath(vertexes, startVertex, key);
			cout << endl;
		}
	}
	system("pause");
	return 0;
}