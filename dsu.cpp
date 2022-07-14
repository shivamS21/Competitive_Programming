#include<bits/stdc++.h>
using namespace std;
// disjoint set union
// there are in short 3 operations to make
// 1. find_set(v)
// 2. make_set(v)
// 3. union_sets(a, b)
void make_set(v){
    parent[v] = v;
}
int find_set(v){
    if(v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
    //this is basically called the path compression which helps to 
    //bring down the query complexities down to constant (logn in some cases which we are going to discuss now)
}
// simple union which in worst case takes around O(n) of time.
void union_sets(int a, int b){
    u = find_set(a);
    v = find_set(b);
    if(u != v){
        //nodes are from different sets
        parent[v] = u;
    }
}
// union by size/rank
// 1. make sets using size of the tree
void make_sets(int v){
    parent[v] = v;
    size[v] = 1;
}
void union_sets(int a, int b){
    u = find_set(a);
    v = find_set(b);
    if(u < v)
        swap(u, v);
    parent[v] = u;
    size[a] += size[b];
}

//almost constant time complexity basically
//2. using the depths of the set
//approach -> we try to connect the tree having smaller depth to the one having bigger depth
void make_set(int u){
    parent[u] = u;
    depth[u] = 0;
}
void union_sets(int a, int b){
    u = find_set(a);
    v = find_set(b);
    if(u != v){
        if(u < v)
        swap(u, v);
    }
    parent[v] = u;
    if(depth[u] == depth[v])
    depth[u]++;
}