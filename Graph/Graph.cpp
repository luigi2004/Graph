// Graph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Graph.h"

int main()
{
	
	Graph<int,int> a;
	a.addVert(9);
	a.addVert(5);
	a.addVert(65);
	a.addVert(300);
	a.addEdge(65, 5, 20);
	a.addEdge(65, 9, 75);
	a.addEdge(65, 300, 30);
	a.addEdge(5, 300, 3);
	a.addEdge(9, 5, 2);
	int degree9 = a.VertDegree(9);
	cout << "degree of vert 9: " << degree9 << endl;
	if (a.neighbors(9, 300))
		cout << "Verts 9 and 300 are neighbors" << endl;
	else
		cout << "Verts 9 and 300 aren't neighbors" << endl;
	vector<int> n = a.VertNeighbors(65);
	for (int i : n)
		cout << i << endl;
    return 0;
}








