// //4. Number of Islands
// You are given a 2D grid of size M x N consisting of characters '0' and '1'. A group of connected '1's
// horizontally or vertically represents a piece of land, forming an island.
// Task: Count the total number of islands present in the grid using BFS/DFS.
// Example:
// Input: grid=[[1,1,0],[0,1,0],[1,0,1]]
// Output: 3
#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& g, int i, int j){
    if(i<0 || j<0 || i>=g.size() || j>=g[0].size() || g[i][j]==0)
        return;

    g[i][j] = 0;

    dfs(g,i+1,j);
    dfs(g,i-1,j);
    dfs(g,i,j+1);
    dfs(g,i,j-1);
}

int main(){
    vector<vector<int>> grid = {
        {1,1,0},
        {0,1,0},
        {1,0,1}
    };

    int m=grid.size(), n=grid[0].size();
    int count = 0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == 1){
                count++;
                dfs(grid,i,j);
            }
        }
    }

    cout << "Islands = " << count << endl;
}
