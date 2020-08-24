/* Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Example 1:

Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation: 
The repeated subarray with maximum length is [3, 2, 1]. */

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<vector<int>> mat(A.size()+1, vector<int>(B.size()+1, 0));
        int i, j;
        int max=0;
        for (i=1;i<=A.size();++i)
        {
            for (j = 1;j<=B.size();++j)
            {
                if (A[i-1] == B[j-1])
                {
                    mat[i][j] = 1 + mat[i-1][j-1];
                    if (mat[i][j] > max)
                        max = mat[i][j];
                }
            }
        }
        
        
        return max;
    }
};