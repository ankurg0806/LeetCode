/* Spiral Matrix

Solution
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7] */


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty())
            return res;
        int r = matrix.size();
        int c = matrix[0].size();
        int rstart=0;
        int rend=r-1;
        int cend = c-1;
        int cstart = 0;
        while(res.size()<r*c)
        {
            int i=rstart;
            for (int j=cstart;j<=cend and rstart<=rend;++j)
            {
                res.push_back(matrix[i][j]);
            }
            rstart++;
            for (int i=rstart;i<=rend and cstart<=cend;++i)
            {
                res.push_back(matrix[i][cend]);
            }
            cend--;
            i=rend;
            for (int j=cend;j>=cstart and rstart<=rend;--j)
            {
                res.push_back(matrix[i][j]);
            }
            rend--;
            for (int i=rend;i>=rstart and cstart<=cend;--i)
            {
                res.push_back(matrix[i][cstart]);
            }
            cstart++;
        }
        return res;
    }
};