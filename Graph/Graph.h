#pragma once
#include <iostream>
#include <unordered_map>
#include"BitField.h"
using namespace std;

/* 
	Graph is a set of tuples between the nodes ,their relationship, 
	and the relationship cost 
	G<N,R,C>

*/

template<class N, class C>
class Graph
{
	struct Node
	{
		int id;
		int degree;
		BitField32 neighbors;
	};
	unordered_map<N,Node> verts;
	int vnum;
	unordered_map<N, unordered_map<N, C>> edges;
public:
	Graph()
	{
		vnum = 0;
	}
	
	~Graph()
	{
		
	}
	void addVert(N item)
	{
		Node vert;
		vert.id = vnum++;
		verts[item] = Node();
	}
	void addEdge(N start, N end, C value)
	{
		(edges[start])[end] = value;
		verts[start].neighbors.set(verts[end].id);
		verts[start].degree++;
		(edges[end])[start] = value;
		verts[end].neighbors.set(verts[start].id);
		verts[end].degree++;
	}
	bool neighbors(N key1,N key2)
	{
		return edges[key1].count(key2) == 1;
	}
	int VertDegree(N key)
	{
		return verts[key].degree;
	}
	vector<N> VertNeighbors(N key)
	{
		vector<N> list;
		for (auto i : edges[key])
		{
			list.push_back(i.first);
		}
		return list;
	}
protected:
	

};

