#include <iostream>
#include <list>
#include <utility>

#include "../includes/graph.hpp"

Graph::Graph(int numVertices) {
    num_v = numVertices;
    adjLists = new AdjList[numVertices];
}

void Graph::addEdge(int src, int dest, int weight){
    adjLists[src].push_front(make_pair(dest, weight));
}

void Graph::addEdge(int src, int dest){
    adjLists[src].push_front(make_pair(dest, 0));
}



void printList(int source, AdjList l) {
    cout << "From: " << source << " -> ";

    for(AdjList::iterator i = l.begin(); i != l.end(); i++ ){
        cout << (*i).first << " " << (*i).second << " | ";
    }

    cout << endl;
}

void Graph::print() {
    for (int i = 0; i < num_v; i++) {
        printList(i, adjLists[i]);
    }
}
 