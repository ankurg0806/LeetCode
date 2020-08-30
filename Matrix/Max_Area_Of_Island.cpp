/* 695. Max Area of Island
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
Example 2:

[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.
Note: The length of each dimension in the given grid does not exceed 50. */

class Solution {
public:
    bool checkBounds(int i,int j,int r,int c){
        return i>=0 && i<r && j>=0 && j<c;
    }
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& visited, int i, int j, int r, int c, int& area)
    {
        if(visited[i][j]) return;
        visited[i][j] = 1;
        ++area;
        vector<pair<int,int>>dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        for(auto dir : dirs)
        {
            int ii = i + dir.first;
            int jj = j + dir.second;
            if(checkBounds(ii,jj,r,c) && grid[ii][jj] == 1)
                dfs(grid, visited, ii, jj, r, c, area);
        }   
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int maxArea = 0;
        vector<vector<int>> visited(r,vector<int>(c));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] == 1)
                { 
                    int area = 0;
                    dfs(grid,visited,i,j,r,c,area);
                    maxArea = area>maxArea?area:maxArea;
                }
            }
        }
        return maxArea;
    }
};