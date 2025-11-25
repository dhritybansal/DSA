// 1. Graph Traversal Count
// Given an undirected graph G(V, E) with V representing the number of vertices numbered from 0 to V-1
// and E representing the number of edges, what is the task? Each edge connects two vertices u and v.
// Task: Determine the number of connected components in the graph.
// Input format: V E followed by E lines of (u v) pairs.
// Example:
// Input: V=5, E=3, edges=[[0,1],[1,2],[3,4]]
// Output: 2
#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<int>& vis){
    vis[u]=1;
    for(int v: adj[u])
        if(!vis[v]) dfs(v, adj, vis);
}

int main(){
    int V=5, E=3;
    vector<vector<int>> adj(V);
    vector<pair<int,int>> edges={{0,1},{1,2},{3,4}};

    for(auto &e: edges){
        adj[e.first].push_back(e.second);
        adj[e.second].push_back(e.first);
    }

    vector<int> vis(V,0);
    int comp = 0;

    for(int i=0;i<V;i++){
        if(!vis[i]){
            comp++;
            dfs(i, adj, vis);
        }
    }

    cout << "Connected Components = " << comp << endl;
}
