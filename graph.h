#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
	struct Vertex {
		int lenghtFromStart;
		int previousVertex;
		bool isVisited;
	};
	int BFS(map <int, vector<int>> list, map <int, Vertex> &vertexes, const int start);
	void printAdjacencyList(map <int, vector<int>>);
	void readWithFile(char *, map <int, vector<int>> &list, int &countEdges, int &startVertex);
	void printPath(map <int, Vertex> &, const int start, int key);

#endif