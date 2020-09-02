/* 323. Number of Connected Components in an Undirected Graph

Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.

Example 1:

Input: n = 5 and edges = [[0, 1], [1, 2], [3, 4]]

     0          3
     |          |
     1 --- 2    4 

Output: 2
Example 2:

Input: n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]]

     0           4
     |           |
     1 --- 2 --- 3

Output:  1
Note:
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges. */

class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& a_list, vector<int>& visited, int v)
    {
        if (visited[v])
            return;
        visited[v] = 1;
        for (auto v1: a_list[v])
        {
            dfs(a_list, visited, v1);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
       unordered_map <int, vector<int>> a_list;
        for (auto edge: edges)
        {
            a_list[edge[0]].push_back(edge[1]);
            a_list[edge[1]].push_back(edge[0]);
        }
        int count = 0;
        vector<int> visited(n,0);
        for (int i=0;i<n;++i)
        {
            if (!visited[i])
            {
                count++;
                dfs (a_list, visited, i);
            }
        }
        return count;
    }
};