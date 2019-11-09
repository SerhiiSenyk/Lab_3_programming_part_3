#include "graph.h"
int BFS(map <int, vector<int>> list, map <int, Vertex> &vertexes, const int start)
{
	int v, maxLenght;
	queue<int> queue;
	queue.push(start);
	for (auto it : list) {
		vertexes[it.first].isVisited = false;
		vertexes[it.first].lenghtFromStart = -1;
	}
	vertexes[start].isVisited = true;
	vertexes[start].lenghtFromStart = maxLenght = 0;
	vertexes[start].previousVertex = start;
	while (!queue.empty()) {
		v = queue.front();
		queue.pop();
		for (int k = 0; k < list[v].size(); ++k) {
			int neighbor = list[v][k];
			if (!vertexes[neighbor].isVisited) {
				queue.push(neighbor);
				vertexes[neighbor].isVisited = true;
				vertexes[neighbor].lenghtFromStart = vertexes[v].lenghtFromStart + 1;
				vertexes[neighbor].previousVertex = v;
				if (vertexes[neighbor].lenghtFromStart > maxLenght) {
					maxLenght = vertexes[neighbor].lenghtFromStart;
				}
			}
		}
	}
	return maxLenght;
}

void printPath(map <int, Vertex> &vertexes, const int start, int key)
{
	if (key != start) {
		printPath(vertexes, start, vertexes[key].previousVertex);
		cout << " - ";
	}
	cout << key;
}

void printAdjacencyList(map <int, vector<int>> list)
{
	for (auto it : list) {
		cout << it.first << " | ";
		for (int j = 0; j < list[it.first].size(); ++j)
			cout << list[it.first][j] << " ";
		cout << endl;
	}
	return;
}

void readWithFile(char *file, map <int, vector<int>> &list, int &countEdges, int &startVertex)
{
	FILE *ptrFile = NULL;
	fopen_s(&ptrFile, file, "r");
	if (ptrFile == NULL) {
		perror("Error open file ");
		system("pause");
		exit(0);
	}
	fscanf_s(ptrFile, "%d %d", &countEdges, &startVertex);
	if (countEdges < 0 || countEdges > 10000)
		exit(0);
	int firstVertex, secondVertex;
	while (!feof(ptrFile)) {
		fscanf_s(ptrFile, "%d %d", &firstVertex, &secondVertex);
		list[firstVertex].push_back(secondVertex);
		list[secondVertex];
	}
	fclose(ptrFile);
	return;
}