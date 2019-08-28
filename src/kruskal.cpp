#include <bits/stdc++.h> 
#include "../includes/graph.hpp"
#include "../includes/aux.hpp"

using namespace std; 

struct Union_Find {

	int *parent, *rnk; 
	int n; 

	Union_Find(int n) {

		// Allocate memory 
		this->n = n; 
		parent = new int[n+1]; 
		rnk = new int[n+1]; 

		// all vertices are in different sets and start with rank 0. 
		for (int i = 0; i <= n; i++) { 
			
			rnk[i] = 0; 

			//every element is parent of itself 
			parent[i] = i; 
		} 
	} 

	// Find the parent of a node 'u' // Path Compression 
	int find(int u) { 

		// Make the parent of the nodes in the path from u--> parent[u] point to parent[u]
		if (u != parent[u]) 
			parent[u] = find(parent[u]); 
		return parent[u]; 
	} 

	// Union by rank 
	void merge(int x, int y) { 

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

int kruskal(EdgeVec edges, int num_V) {

	int weight = 0;

	// Create disjoint sets 
	Union_Find ds(num_V); 

	// For each edge (sorted)
	EdgeVec::iterator i; 
	for (i = edges.begin(); i != edges.end(); i++) {

		int u = i->second.first; 
		int v = i->second.second; 

		int set_u = ds.find(u); 
		int set_v = ds.find(v); 

		// Check if is a cicle or not
		if (set_u != set_v) {

			// Current edge will be in the MST 
			cout << "Edge from " << u << " to " << v << " - weight: " << i->first << endl; 

			// Update MST weight 
			weight += i->first; 

			// Merge sets 
			ds.merge(set_u, set_v); 
		} 
	} 

	return weight; 
} 

int main(int argc, char *argv[]) { 
    
    ifstream file;
    if(!getFile(argc, argv, file)) {
        exit(0);
    }

    Graph graph = create_graph(file);

	cout << "Edges of MST are \n\n"; 

	int mst_wt = kruskal(graph.getEdges(), graph.num_v); 

	cout << endl << "Weight of MST is " << mst_wt << endl; 

	return 0; 
} 
