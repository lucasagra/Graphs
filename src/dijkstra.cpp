#include <iostream>
#include <list>
#include <utility>
#include <bits/stdc++.h> 
  
using namespace std; 
  
#include "../includes/graph.hpp"
#include "../includes/aux.hpp"

typedef pair<int, int> gPair; 


void dijkstra(Graph graph, int src) {

    cout << "Running Djikstra from source: " << src << endl;

    int numV = graph.num_v;

    vector<int> dist(numV, INT_MAX);
    vector<int> parent(numV, -1);
    priority_queue<gPair> pq;

    dist[src] = 0;
    parent[src] = src;

    pq.push({dist[src], src});

    while (!pq.empty()) {

        int u = pq.top().second;

        pq.pop();
        
        list<gPair>::iterator i;
        for (i = graph.adjLists[u].begin(); i != graph.adjLists[u].end(); ++i) {
            int v = i->first;
            int w = i->second;

            //cout << "Adjacents from: " << u << " is " << v << " with " << w << endl;

            if(dist[v] > (dist[u] + w)) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    
    cout << "to \t dist" << endl;
    for (int i = 0; i < numV; ++i)
        cout << i << "\t " << dist[i] << endl;

    cout << endl << "vetex \t parent" << endl;
    for (int i = 0; i < numV; ++i)
        cout << i << "\t " << parent[i] << endl;

}


int main (int argc, char *argv[]) {

    ifstream file;
    if(!getFile(argc, argv, file)) {
        exit(0);
    }

    Graph graph = create_graph(file);

    dijkstra(graph, 0);

    return 0;
}