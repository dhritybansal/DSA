// //3. Network Delay Time
// You are given a directed weighted graph G(V, E) and an array times[] where times[i] = (u, v, w) represents
// an edge from node u to node v with weight w.
// Task: Given a starting node K, find how long it takes for all nodes to receive the signal.
// If some nodes cannot be reached, return -1.
// Example:
// Input: N=4, K=2, times=[[2,1,1],[2,3,1],[3,4,1]]
// Output: 2
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N = 4, K = 2;
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};

    vector<vector<pair<int,int>>> adj(N+1);
    for(auto &t : times)
        adj[t[0]].push_back({t[1], t[2]});

    vector<int> dist(N+1, 1e9);
    dist[K] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,K});

    while(!pq.empty()){
        auto [d,u] = pq.top(); pq.pop();

        for(auto &p: adj[u]){
            int v=p.first, w=p.second;
            if(dist[v] > d + w){
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }

    int ans = 0;
    for(int i=1;i<=N;i++){
        if(dist[i] == 1e9){
            cout << -1;
            return 0;
        }
        ans = max(ans, dist[i]);
    }

    cout << ans;
}
