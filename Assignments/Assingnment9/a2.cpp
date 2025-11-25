// //2. Shortest Path in Grid
// You are given a weighted grid size of m x n. Each cell contains a non-negative cost. Interpret the grid as a
// graph where each cell is a node and edges exist between adjacent horizontal/vertical cells with weights
// equal to the destination cell cost.
// Task: Determine the minimum total cost from (0,0) to (m-1,n-1) using Dijkstra.
// Example:
// Input: grid=[[1,2,3],[4,5,6],[7,8,9]]
// Output: 21
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<vector<int>> grid = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dist(m, vector<int>(n, 1e9));

    dist[0][0] = grid[0][0];
    priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
    > pq;

    pq.push({grid[0][0], {0,0}});

    int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    while(!pq.empty()){
        auto [d, pos] = pq.top(); pq.pop();
        int x = pos.first, y = pos.second;

        for(auto &dir : dirs){
            int nx = x + dir[0], ny = y + dir[1];

            if(nx>=0 && ny>=0 && nx<m && ny<n){
                if(dist[nx][ny] > d + grid[nx][ny]){
                    dist[nx][ny] = d + grid[nx][ny];
                    pq.push({dist[nx][ny], {nx,ny}});
                }
            }
        }
    }

    cout << "Min Cost Path = " << dist[m-1][n-1] << endl;
}
