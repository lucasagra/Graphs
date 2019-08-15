#ifndef GRAPH_HPP
#define GRAPH_HPP

using namespace std;

typedef list<pair<int,int>> AdjList;

class Graph {

    public:
        int num_v;
        AdjList* adjLists;
        Graph(int V);
        void addEdge(int src, int dest, int weight);
        void addEdge(int src, int dest);
        void print();
};


#endif
