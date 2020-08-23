/* All Paths From Source to Target

Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.

The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.

Example:

Input: [[1,2], [3], [3], []] 
Output: [[0,1,3],[0,2,3]] 
Explanation: The graph looks like this:

    0--->1
	|    |
	v    v
	2--->3
	
There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3. */

class Solution {
public:
     
    void allPathsUtils(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& path, vector<vector<int>>& res, int vertex)
    {
        for (int i=0;i< graph[vertex].size();++i)
        {
            if (!visited[graph[vertex][i]])
            {
                visited[graph[vertex][i]] = true;
                path.push_back(graph[vertex][i]);
                
                if (graph[vertex][i] == graph.size()-1)
                {
                    res.push_back(path);
                }
                else
                {
                    allPathsUtils(graph, visited, path, res, graph[vertex][i]);
                }
                visited[graph[vertex][i]] = false;
                path.pop_back();
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size(), false);
        vector<vector<int>> res;
        vector<int> path;
        if (graph[0].size()==0)
            return res;
        visited[0] = true;
        path.push_back(0);
        allPathsUtils(graph, visited, path, res, 0);
        return res;
        
    }
};