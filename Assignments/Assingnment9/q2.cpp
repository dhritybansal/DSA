//2. DFS Traversal
#include <iostream>
#include <vector>
using namespace std;

void dfsUtil(int u, vector<vector<int>>& adj, vector<int>& vis){
    vis[u] = 1;
    cout << u << " ";

    for(int v : adj[u])
        if(!vis[v])
            dfsUtil(v, adj, vis);
}

void dfs(int src, vector<vector<int>>& adj, int V){
    vector<int> vis(V, 0);
    cout << "DFS: ";
    dfsUtil(src, adj, vis);
    cout << endl;
}

int main(){
    int V = 5;
    vector<vector<int>> adj = {
        {1,2}, {0,3}, {0}, {1,4}, {3}
    };

    dfs(0, adj, V);
}
