/* There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
			  */

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<int> result;
        for (auto& preReq: prerequisites)
        {
            indegree[preReq[0]]++;
        }
        stack<int> mystack;
        for (int i=0; i<numCourses; ++i)
        {
            if (indegree[i] == 0)
            {
                mystack.push(i);
                cout<<i<<endl;
            }
        }
        while (!mystack.empty())
        {
            int current_vertex = mystack.top();
            mystack.pop();
            result.push_back(current_vertex);
            for (int i=0; i< prerequisites.size(); ++i)
            {
                if (prerequisites[i][1] == current_vertex)
                {
                    indegree[prerequisites[i][0]]--;
                    if (indegree[prerequisites[i][0]] == 0)
                     {
                         mystack.push(prerequisites[i][0]);
                     }
                }
            }
        }
        if (result.size() == numCourses)
            return true;
        return false;
    }
};