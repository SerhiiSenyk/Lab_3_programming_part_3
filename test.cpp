#include "gtest/gtest.h"
#include "graph.h"
TEST(TestBFS, File_bfs_example) {
	int countEdges, startVertex;
	map <int, vector<int>> list;
	map <int, Vertex> vertexes;
	char fileName[300] = "D:\\Internet of Things\\Semestr #3\\Algorithms\\Lab_3\\bfs_example_3.txt";
	readWithFile(fileName, list, countEdges, startVertex);
	int maxLenght = BFS(list, vertexes, startVertex);
	int expectedLenght = 11;
	EXPECT_EQ(maxLenght, expectedLenght);
}