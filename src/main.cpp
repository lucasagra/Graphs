#include <iostream>
#include <list>
#include <utility>

#include "../includes/graph.hpp"



int main () {
   int n = 4;
    
   
   Graph graph = Graph(4);
   graph.addEdge(0, 1);
   graph.addEdge(0, 2, 0);
   graph.addEdge(1, 2, 0);
   graph.addEdge(2, 3, 0);
   
   graph.print();
    
   return 0;
}
