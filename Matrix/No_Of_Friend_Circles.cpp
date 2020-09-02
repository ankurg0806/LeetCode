547. Friend Circles

There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.

Example 1:

Input: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
The 2nd student himself is in a friend circle. So return 2.
 

Example 2:

Input: 
[[1,1,0],
 [1,1,1],
 [0,1,1]]
Output: 1
Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, 
so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.

class Solution {
public:
    void findCircleUtil(vector<vector<int>>& M, vector<int>& visited, int j)
    {
        visited[j] = 1;
        for (int k=0;k<M.size();++k)
        {
            if (M[j][k] == 1 and visited[k]!=1)
            {
                findCircleUtil(M, visited, k);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        int no_of_frnz = M.size();
        int grp=0;
        vector<int> visited(no_of_frnz,0);
        for (int i=0;i<no_of_frnz;++i)
        {
            if (visited[i]!=1)
            {
                grp++;
                visited[i] = 1;
                for (int j=0;j<no_of_frnz;++j)
                {
                    if (M[i][j] == 1)
                    {
                        findCircleUtil(M, visited, j);
                    }
                }
            }
        }
        return grp;
    }
};