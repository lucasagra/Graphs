#include <iostream>
#include <list>
#include <utility>
#include <bits/stdc++.h> 
  
using namespace std; 
  
#include "../includes/graph.hpp"
#include "../includes/aux.hpp"

typedef pair<int, int> gPair; 


void bfs(Graph graph, int src) {
    int parent[graph.num_v];
    for (int i = 0; i < graph.num_v; i++)
        parent[i] = -1;
    
    parent[src] = src;

    queue<int> q;

    q.push(src);

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        
        cout << "Visiting: " << u << endl;

        list<gPair>::iterator i;
        for(i = graph.adjLists[u].begin(); i != graph.adjLists[u].end(); i++) {
            if(parent[i->first] == -1) {
                parent[i->first] = u;
                q.push(i->first);
            }
        }
    }
    
    cout << endl << "vetex \t parent" << endl;
    for (int i = 0; i < graph.num_v; ++i)
        cout << i << "\t " << parent[i] << endl;
    cout << endl;
    
}


int main (int argc, char *argv[]) {

    ifstream file;
    if(!getFile(argc, argv, file)) {
        exit(0);
    }

    Graph graph = create_graph(file);

    bfs(graph, 0);

    return 0;
}