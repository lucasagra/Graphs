# Graphs
Graphs Algorithms implemented

- [x] BFS
- [x] DFS
- [x] Dijkstra
- [x] Bellman Ford
- [x] Prim
- [x] Kruskal

On the main folder:
To start cmake
`cmake .`

To compile algorithms
`make`

To run algorithm
`./algorithm_name examples/input`

where input is a file like this:

```
2 1
1 2 10
```

Where the first line contains V and E, the number of vertices and edges,
followed by E lines containing each edge as:

`vertex_src vertex_dest weight`
