#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
using namespace std;

typedef list<pair<int, int>> AdjList;
typedef pair<int, int> FromTo;
typedef pair<int, FromTo> weightPair;
typedef vector<weightPair> weightVec;

class Graph {

    public:
        int num_v;
        int num_e;
        AdjList* adjLists;
        Graph(int V);
        weightVec getVectorOfWeights(); // vec{weight, {src, dest}}
        void addEdge(int src, int dest, int weight);
        void addEdge(int src, int dest);
        void print();
};


#endif
