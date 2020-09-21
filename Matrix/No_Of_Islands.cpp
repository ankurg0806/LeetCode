/* 200. Number of Islands

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3 */

class Solution {
public:
    bool valid (int i, int j, int r, int c)
    {
        return i>=0 and i<r and j>=0 and j<c;
    }
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j, int r, int c)
    {
        visited[i][j] = true;
        vector<pair<int,int>>dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        for(auto dir : dirs)
        {
            int ii = i + dir.first;
            int jj = j + dir.second;
            if(valid(ii,jj,r,c) && grid[ii][jj] == '1' and not visited[ii][jj])
                dfs(grid, visited, ii, jj, r, c);
        }  
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<bool>> visited(r, vector<bool>(c, false)); 
        int count=0;
        for (int i=0;i <r; i++)
        {
            for (int j=0;j<c;j++)
            {
                if (!visited[i][j] and grid[i][j] == '1')
                {
                    count++;
                    dfs(grid, visited, i, j, r, c);
                }
            }
        }
        return count;
    }
};