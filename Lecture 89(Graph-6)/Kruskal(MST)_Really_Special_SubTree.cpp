/*
Kruskal (MST - Minimum Spanning Tree) : Really Special SubTree [Hacker Rank]
===========================================================
Given an undirected weighted connected graph, find the Really Special SubTree in it. The Really Special SubTree is defined as a subgraph consisting of all the nodes in the graph and:

-> There is only one exclusive path from a node to every other node.
-> The subgraph is of minimum overall weight (sum of all edges) among all such subgraphs.
-> No cycles are formed.

To create the Really Special SubTree, always pick the edge with smallest weight. Determine if including it will create a cycle. If so, ignore the edge. If there are edges of equal weight available:

* Choose the edge that minimizes the sum u+v+wt where u and v are vertices and wt is the edge weight.
* If there is still collision, chose using any of them

Print the overall weight of the tree formed using the rules.

For example, given the following edges:
u   v   wt
1   2   2
2   3   3
3   1   5

First choose 1 -> 2 at weight 2. Next choose 2 -> 3 at weight 3. All nodes are connected without cycle for a total weight 3 + 2 = 5 
*/

/*
========== Understanding ==============
Special Subtree ===> tree ----> no cycle 
Subgraph ==> it containsn all the vertices.

MST = > Minimum Spanning Tree
Tree -> graph having no cycle
Spanning -> subgraph having all vertices but min no. of edges available to keep it connected.
*/ 