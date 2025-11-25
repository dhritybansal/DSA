
//5. Dijkstra’s Shortest Path
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int V = 5;
    vector<vector<pair<int,int>>> adj(V);

    adj[0]={{1,2},{2,4}};
    adj[1]={{2,1},{3,7}};
    adj[2]={{4,3}};
    adj[3]={{4,1}};
    adj[4]={};

    vector<int> dist(V, 1e9);
    dist[0] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,0});

    while(!pq.empty()){
        auto [d,u] = pq.top();
        pq.pop();

        for(auto &p: adj[u]){
            int v = p.first, w = p.second;
            if(dist[v] > d + w){
                dist[v] = d + w;
                pq.push({dist[v],v});
            }
        }
    }

    cout << "Dijkstra distances:\n";
    for(int i=0;i<V;i++)
        cout << i << " : " << dist[i] << endl;
}
