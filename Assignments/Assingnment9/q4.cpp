//3. Minimum Spanning Tree – prim
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int V = 5;
    vector<vector<pair<int,int>>> adj(V);

    adj[0] = {{1,2},{3,6}};
    adj[1] = {{0,2},{2,3},{3,8},{4,5}};
    adj[2] = {{1,3},{4,7}};
    adj[3] = {{0,6},{1,8}};
    adj[4] = {{1,5},{2,7}};

    vector<int> key(V, INT_MAX), parent(V, -1), mst(V, 0);
    key[0] = 0;

    for(int i=0;i<V;i++){
        int u = -1;

        for(int j=0;j<V;j++)
            if(!mst[j] && (u == -1 || key[j] < key[u]))
                u = j;

        mst[u] = 1;

        for(auto &p : adj[u]){
            int v = p.first, w = p.second;

            if(!mst[v] && w < key[v]){
                key[v] = w;
                parent[v] = u;
            }
        }
    }

    cout << "Prim MST:\n";
    for(int i=1;i<V;i++)
        cout << parent[i] << " - " << i << " : " << key[i] << endl;
}
