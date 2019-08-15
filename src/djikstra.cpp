#include <iostream>
#include <list>
#include <utility>
#include <bits/stdc++.h> 
  
using namespace std; 
  
#include "../includes/graph.hpp"

typedef pair<int, int> gPair; 


void dijkstra(Graph graph, int src) {

    cout << "Running Djikstra from source: " << src << endl;

    int numV = graph.num_v;

    vector<int> dist(numV, INT_MAX);
    priority_queue<gPair> pq;

    dist[src] = 0;

    pq.push(make_pair(dist[src], src));

    while (!pq.empty()) {

        int u = pq.top().second;

        pq.pop();
        
        for (list<gPair>::iterator i = graph.adjLists[u].begin(); i != graph.adjLists[u].end(); ++i) {
            int v = (*i).first;
            int w = (*i).second;

            //cout << "Adjacents from: " << u << " is " << v << " with " << w << endl;

            if(dist[v] > (dist[u] + w)) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    
    printf("from \t dist\n");
    for (int i = 0; i < numV; ++i) 
        printf("%d \t %d\n", i, dist[i]); 

}


int main () {

    Graph graph = Graph(4);
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 2);
    graph.addEdge(1, 2, 1);
    graph.addEdge(2, 3, 1);
    graph.addEdge(3, 1, 1);
    graph.addEdge(2, 1, 10);


    dijkstra(graph, 0);

    return 0;
}