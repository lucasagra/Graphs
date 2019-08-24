// C++ program for Kruskal's algorithm to find Minimum Spanning Tree of a given connected, undirected and weighted graph 
#include<bits/stdc++.h> 
#include "../includes/graph.hpp"

using namespace std; 

typedef pair<int, int> gPair;

int prim(Graph graph) 
{ 
    int mst_cost = 0;
    
    int key[graph.num_v];
    int parents[graph.num_v];
    bool visited[graph.num_v];

    priority_queue<gPair, vector<gPair>, greater<gPair> > pq;

    for(int i = 0; i < graph.num_v; ++i){
        key[i] = INT_MAX;
        parents[i] = -1;
        visited[i] = false;
    }

    key[0] = 0;
    pq.push({key[0], 0});

    while(!pq.empty()) {
        int u = pq.top().second;
        visited[u] = true;
        
        pq.pop();

        AdjList::iterator i; 
        for (i = graph.adjLists[u].begin(); i != graph.adjLists[u].end(); ++i) {
            int v = i->first;
            int w = i->second;

            if (!visited[v] && w < key[v]) {
                key[v] = w;
                parents[v] = u;
                pq.push({w, v});
            }
        }
    }

    for (int i = 1; i < graph.num_v; ++i) {
        cout << "Edge from " << parents[i] << " to " << i << " - weight: " << key[i] << endl; 
        mst_cost += key[i];
    }

    return mst_cost;
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

	int mst_wt = prim(g); 

	cout << "\nWeight of MST is " << mst_wt << endl; 

	return 0; 
} 
