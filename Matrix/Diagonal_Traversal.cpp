/* 498. Diagonal Traverse
Medium

858

348

Add to List

Share
Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

 

Example:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

Output:  [1,2,4,7,5,3,6,8,9] */

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int i=0, j=0;
        bool up = true;
        vector<int> res;
        if (matrix.empty())
            return res;
        int count=0;
        while (count<matrix.size()*matrix[0].size())
        {
            if (up)
            {
                if (count==matrix.size()*matrix[0].size())
                    break;
                while (i>=0 and j<matrix[0].size())
                {
                    count++;
                    res.push_back(matrix[i][j]);
                    i--;j++;
                }
                if (j== matrix[0].size())
                {
                    j--;
                    i++;i++;
                }
                if (i<0)
                    i=0;
                up = false;
            }
            if (!up)
            {
                if (count==matrix.size()*matrix[0].size())
                    break;
                while (i<matrix.size() and j>=0)
                {
                    count++;
                    res.push_back(matrix[i][j]);
                    i++;j--;
                }
                if (i==matrix.size())
                {
                    i--;
                    j++;j++;
                }
                if (j<0)
                    j=0;
                up = true;
            }
        }
        return res;
    }
};