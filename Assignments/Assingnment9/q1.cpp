//1. BFS Traversal

#include <iostream>
#include <vector>
using namespace std;

void bfs(int src, vector<vector<int>>& adj, int V){
    vector<int> vis(V, 0);
    queue<int> q;

    vis[src] = 1;
    q.push(src);

    cout << "BFS: ";
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout << u << " ";

        for(int v : adj[u]){
            if(!vis[v]){
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    cout << endl;
}

int main(){
    int V = 5;
    vector<vector<int>> adj = {
        {1,2}, {0,3}, {0}, {1,4}, {3}
    };

    bfs(0, adj, V);
}
