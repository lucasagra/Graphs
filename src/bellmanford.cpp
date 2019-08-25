#include<bits/stdc++.h> 
#include "../includes/graph.hpp"
#include "../includes/aux.hpp"

using namespace std; 

bool bellman_ford(Graph graph, int src) {

    int dist[graph.num_v];

    for (int i = 0; i < graph.num_v; ++i) {
        dist[i] = INT_MAX;
    }

    dist[src] = 0;

    // for each vertex
    for (int i = 1; i < graph.num_v; i++) {

        // iterate for all edges
        for (int j = 0; j < graph.num_v; j++) {
            list<pair<int,int>>::iterator k;
            for(k = graph.adjLists[j].begin(); k != graph.adjLists[j].end(); ++k) {
                int u = j;
                int v = k->first;
                int w = k->second;

                if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

    // iterate for all edges
    for (int j = 0; j < graph.num_v; j++) {
        list<pair<int,int>>::iterator k;
        for(k = graph.adjLists[j].begin(); k != graph.adjLists[j].end(); ++k) {
            int u = j;
            int v = k->first;
            int w = k->second;

            if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                return false; // negative cycle is detected
            }
        }
    }

    cout << "Vertex Distance from Source" << endl; 
    for (int i = 0; i < graph.num_v; ++i) 
        cout << "\t\t" << i << "\t\t" << dist[i] << endl;

    return true;
}

int main(int argc, char *argv[]) {
    
    ifstream file;
    if(!getFile(argc, argv, file)) {
        exit(0);
    }

    Graph graph = create_graph(file);

    if (!bellman_ford(graph, 0))
        cout << "Graph contains negative cycle \n \n";

    return 0;
}