- [Dynamic programming](#dynamic-programming)
- [STL container](#stl-container)
  * [Associative containers](#associative-containers)
  * [Sequence containers](#sequence-containers)
- [Tree structure](#tree-structure)
- [Geometry problems](#geometry-problems)
- [Modulo operation](#modulo-operation)

# Dynamic programming
  - 2 consecutive rows Space Optimized DP. Do not forget this one: for (int j = 0; j <= n; ++j)if(d[j][i%2])d[j][(i+1)%2]=d[j][i%2];
  
# STL container
  ## Associative containers
  - set for multiple same elements
  
  ## Sequence containers
  - do not forget to check the last element of the array.
  - match two arrays: len(array_a) maybe be larger or smaller than len(array_b)
  
# Tree structure
  - the leaf node will not execute for (int v:vec[u]) {if(v==fa)continue;dfssum(v,u);sum[u]+=sum[v];***happy[u]=(sum[u]+hidx[u])/2;***}
  - if a tree only have two nodes, root node and left node all have one next edge
    
# Geometry problems
  - draw graphs!

# Modulo operation
  - It can influence the results of sort[D. Maximum Distributed Tree](https://codeforces.com/contest/1401/problem/D)
  
  
