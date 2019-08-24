// C++ program for Kruskal's algorithm to find Minimum Spanning Tree of a given connected, undirected and weighted graph 
#include<bits/stdc++.h> 
#include "../includes/graph.hpp"

using namespace std; 

struct DisjointSets 
{ 
	int *parent, *rnk; 
	int n; 

	DisjointSets(int n) 
	{ 
		// Allocate memory 
		this->n = n; 
		parent = new int[n+1]; 
		rnk = new int[n+1]; 

		// Initially, all vertices are in different sets and have rank 0. 
		for (int i = 0; i <= n; i++) 
		{ 
			rnk[i] = 0; 

			//every element is parent of itself 
			parent[i] = i; 
		} 
	} 

	// Find the parent of a node 'u' 
	// Path Compression 
	int find(int u) 
	{ 
		// Make the parent of the nodes in the path from u--> parent[u] point to parent[u]
		if (u != parent[u]) 
			parent[u] = find(parent[u]); 
		return parent[u]; 
	} 

	// Union by rank 
	void merge(int x, int y) 
	{ 
		x = find(x), y = find(y); 

		// Make tree with smaller height a subtree of the other tree
		if (rnk[x] > rnk[y]) 
			parent[y] = x; 
		else 
			// If rnk[x] <= rnk[y] 
			parent[x] = y; 

		if (rnk[x] == rnk[y]) 
			rnk[y]++; 
	} 
}; 

int kruskal(vector<weightPair> edges, int num_V) 
{ 
	int mst_wt = 0;

	// Create disjoint sets 
	DisjointSets ds(num_V); 

	// Iterate through all sorted edges 
	vector<weightPair>::iterator i; 
	for (i=edges.begin(); i != edges.end(); i++) 
	{ 
		int u = i->second.first; 
		int v = i->second.second; 

		int set_u = ds.find(u); 
		int set_v = ds.find(v); 

		// Check if is a cicle or not (Cycle is created if u and v belong to same set) 
		if (set_u != set_v) 
		{ 
			// Current edge will be in the MST 
			cout << "Edge from " << u << " to " << v << endl; 

			// Update MST weight 
			mst_wt += i->first; 

			// Merge sets 
			ds.merge(set_u, set_v); 
		} 
	} 

	return mst_wt; 
} 

int main() 
{ 
	int V = 9; 
	Graph g = Graph(V); 

	g.addEdge(0, 1, 4); 
	g.addEdge(0, 7, 8); 
	g.addEdge(1, 2, 8); 
	g.addEdge(1, 7, 11); 
	g.addEdge(2, 3, 7); 
	g.addEdge(2, 8, 2); 
	g.addEdge(2, 5, 4); 
	g.addEdge(3, 4, 9); 
	g.addEdge(3, 5, 14); 
	g.addEdge(4, 5, 10); 
	g.addEdge(5, 6, 2); 
	g.addEdge(6, 7, 1); 
	g.addEdge(6, 8, 6); 
	g.addEdge(7, 8, 7); 

	cout << "Edges of MST are \n\n"; 

	int mst_wt = kruskal(g.getVectorOfWeights(), g.num_v); 

	cout << "\nWeight of MST is " << mst_wt << endl; 

	return 0; 
} 
