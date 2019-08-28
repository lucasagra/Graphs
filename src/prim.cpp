#include<bits/stdc++.h> 
#include "../includes/graph.hpp"
#include "../includes/aux.hpp"

using namespace std; 

typedef pair<int, int> intPair;

int prim(Graph graph) {

	cout << "Running Prim \n\n"; 

    int mst_cost = 0;

    vector<int> lowestDist(graph.num_v, INT_MAX);
    vector<int> parents(graph.num_v, -1);
    vector<bool> visited(graph.num_v, false);
    
    priority_queue<intPair, vector<intPair>, greater<intPair> > pq;
    

    lowestDist[0] = 0;
    pq.push({lowestDist[0], 0});

    while(!pq.empty()) {

        int u = pq.top().second;
        visited[u] = true;
        
        pq.pop();

        AdjList::iterator i; 
        for (i = graph.adjLists[u].begin(); i != graph.adjLists[u].end(); ++i) {
            int v = i->first;
            int w = i->second;

            if (!visited[v] && w < lowestDist[v]) {
                lowestDist[v] = w;
                parents[v] = u;
                pq.push({w, v});
            }
        }
    }

    for (int i = 1; i < graph.num_v; ++i) {
        cout << "Edge from " << parents[i] << " to " << i << " - weight: " << lowestDist[i] << endl; 
        mst_cost += lowestDist[i];
    }

    return mst_cost;
} 

int main(int argc, char *argv[]) {
    
    ifstream file;
    if(!getFile(argc, argv, file)) {
        exit(0);
    }

    Graph graph = create_graph(file);

	int mst_wt = prim(graph); 

	cout << "\nWeight of MST is " << mst_wt << endl; 


	return 0; 
} 
