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

//На етапі X опрацьовувати всі вершини з відстанню Х від початкової

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;
struct Vertex;
int** readWithFile(int &countEdges, int &startVertex);
void display(int **graph, const int countEdges);
int BFS(map <int, vector<int>> list, map <int, Vertex> &vertex, const int start);
void printAdjacencyList(map <int, vector<int>> list);  
void convertToAdjacencyList(int **graph, map <int, vector<int>> &list, int countEdges);

struct Vertex {
	int lenghtFromStart;
	int previousVertex;
	bool isVisited;
};

void printPath(map <int, Vertex> vertex, const int start, int key);

int main()
{
	const int N = 2;
	int countEdges ,startVertex;
	int **graph = readWithFile(countEdges, startVertex);
	display(graph, countEdges);
	map <int, vector<int>> list;
	map <int, Vertex> vertex;
	convertToAdjacencyList(graph, list, countEdges);
	printAdjacencyList(list);
	int maxLenght = BFS(list, vertex, startVertex);

	for (auto i : list) {
		cout << i.first << " " << vertex[i.first].lenghtFromStart << endl;
	}
	for (auto i : list) {
		cout << i.first << " " << vertex[i.first].isVisited << endl;
	}
	cout << "Max lenght = " << maxLenght << endl;
	for (auto it : vertex) {
		if (vertex[it.first].lenghtFromStart == maxLenght) {
			cout << "Vertex : " << it.first << endl;
			cout << "Path from start vertex : ";
			int key = it.first;
			printPath(vertex, startVertex, key);
			cout << endl;
		}
	}

	for (int i = 0; i < countEdges; ++i) {
		free(graph[i]);
	}
	free(graph);
	system("pause");
	return 0;
}

void convertToAdjacencyList(int **graph, map<int, vector<int>> &list, int countEdges)
{
	for (int i = 0; i < countEdges; ++i) {
		list[graph[i][0]].push_back(graph[i][1]);
		list[graph[i][1]];
	}
	return;
}

void printAdjacencyList(map <int, vector<int>> list)
{
	cout << "countVertex : " << list.size() << endl;
	for (auto it : list) {
		cout << it.first << " | ";
		for (int j = 0; j < list[it.first].size(); ++j)
			cout << list[it.first][j] << " ";
		cout << endl;
	}
	return;
}

int BFS(map <int, vector<int>> list, map <int, Vertex> &vertex, const int start)
{
	int v, maxLenght;
	queue<int> queue;
	queue.push(start);
	for (auto it : list) {
		vertex[it.first].isVisited = false;
		vertex[it.first].lenghtFromStart = -1;
	}
	vertex[start].isVisited = true;
	vertex[start].lenghtFromStart = maxLenght = 0;
	vertex[start].previousVertex = start;
	while (!queue.empty()) {
		v = queue.front();
		queue.pop();
		for (int k = 0; k < list[v].size(); ++k) {
			int neighbor = list[v][k];
			if (!vertex[neighbor].isVisited) {
				queue.push(neighbor);
				vertex[neighbor].isVisited = true;
				vertex[neighbor].lenghtFromStart = vertex[v].lenghtFromStart + 1;
				vertex[neighbor].previousVertex = v;
				if (vertex[neighbor].lenghtFromStart > maxLenght) {
					maxLenght = vertex[neighbor].lenghtFromStart;
				}
			}
		}
	}
	return maxLenght;
}

int **readWithFile(int &countEdges, int &startVertex)
{
	FILE *ptrFile = NULL;
	fopen_s(&ptrFile, "graph.txt", "r");
	if (ptrFile == NULL) {
		perror("Error open file <graph.txt> ");
		system("pause");
		exit(0);
	}
	fscanf_s(ptrFile, "%d %d", &countEdges, &startVertex);
	if (countEdges < 0 || countEdges > 10000)
		exit(0);
	int **graph = (int**)calloc(countEdges, sizeof(int*));
	for (int i = 0; i < countEdges; ++i)
		graph[i] = (int*)calloc(2, sizeof(int));
	int i = 0;
	while (!feof(ptrFile)) {
		fscanf_s(ptrFile, "%d %d", &graph[i][0], &graph[i][1]);
		++i;
	}
	fclose(ptrFile);
	return graph;
}

void printPath(map <int, Vertex> vertex, const int start, int key)
{
	if (key != start) {
		printPath(vertex, start, vertex[key].previousVertex);
		cout << " - ";
	}
	cout << key;
}

void display(int **graph, const int countEdges)
{
	printf("In :\n");
	cout << countEdges << endl;
	for (int i = 0; i < countEdges; ++i) {
		for (int j = 0; j < 2; ++j)
			cout << graph[i][j] << "  ";
		cout << endl;
	}
	cout << endl;
}