#include<bits/stdc++.h> 
#include "../includes/graph.hpp"

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

int main() {
    
    Graph grp(5);
    grp.addEdge(0, 1, 6);
    grp.addEdge(0, 2, 7);
    grp.addEdge(1, 3, 5);
    grp.addEdge(1, 4, -4);
    grp.addEdge(1, 2, 8);
    grp.addEdge(2, 3, -3);
    grp.addEdge(2, 4, 9);
    grp.addEdge(3, 1, -2);
    grp.addEdge(4, 0, 2);
    grp.addEdge(4, 3, 7);

    if (!bellman_ford(grp, 0))
        std::cout << "Graph contains negative cycle \n \n";

    Graph grp2(5);
    grp2.addEdge(0, 1, 6);
    grp2.addEdge(0, 2, 7);
    grp2.addEdge(1, 3, 5);
    grp2.addEdge(1, 4, -4);
    grp2.addEdge(1, 2, 4); // negative loop here
    grp2.addEdge(2, 3, -3);
    grp2.addEdge(2, 4, 9);
    grp2.addEdge(3, 1, -2);
    grp2.addEdge(4, 0, 2);
    grp2.addEdge(4, 3, 7);

    if (!bellman_ford(grp2, 0))
        std::cout << "Graph contains negative cycle \n \n";

}