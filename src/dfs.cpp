#include <iostream>
#include <list>
#include <utility>
#include <bits/stdc++.h> 
  
using namespace std; 
  
#include "../includes/graph.hpp"
#include "../includes/aux.hpp"

typedef pair<int, int> gPair; 

void dfs(Graph graph, int src, int parent[]) {
    
    list<gPair>::iterator i;
    for(i = graph.adjLists[src].begin(); i != graph.adjLists[src].end(); i++) {
        if(parent[i->first] == -1) {
            parent[i->first] = src;
            dfs(graph, i->first, parent);
        }
    }

    cout << "Visiting: " << src << endl;
}

void graph_dfs(Graph graph, int src) {

    cout << "Running DFS from source: " << src << endl;
    
    int parent[graph.num_v];

    for(int i = 0; i < graph.num_v; ++i)
        parent[i] = -1;

    parent[src] = src;

    dfs(graph, src, parent);

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

    graph_dfs(graph, 0);

    return 0;
}