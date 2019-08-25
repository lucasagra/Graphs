#include <iostream>
#include <list>
#include <utility>
#include <bits/stdc++.h> 

#include "../includes/graph.hpp"

Graph::Graph(int numVertices) {
    num_v = numVertices;
    num_e = 0;
    adjLists = new AdjList[numVertices];
}

void Graph::addEdge(int src, int dest, int weight){
    adjLists[src].push_front(make_pair(dest, weight));
    num_e++;
}

void Graph::addEdge(int src, int dest){
    adjLists[src].push_front(make_pair(dest, 0));
    num_e++;
}

EdgeVec Graph:: getEdges() {

    EdgeVec result = EdgeVec(num_e);

    for(int i = 0; i < num_v; ++i) {
        int u = i;
        
        AdjList::iterator j;
        for (j = adjLists[i].begin(); j != adjLists[i].end(); ++j) {
            int v = j->first;
            int w = j->second;

            pair<int, pair<int, int>> wpair = {w, {u, v}};

            result.push_back(wpair);
        }
    }

    sort(result.begin(), result.end()); 
    return result;
}

void printList(int source, AdjList l) {
    cout << "From: " << source << " -> ";

    AdjList::iterator i;
    for(i = l.begin(); i != l.end(); i++ ){
        cout << i->first << " " << i->second << " | ";
    }

    cout << endl;
}

void Graph::print() {
    for (int i = 0; i < num_v; i++) {
        printList(i, adjLists[i]);
    }
}
 