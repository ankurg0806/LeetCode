/* Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
] */


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> prev_temp;
        for (int i=1; i<=numRows; ++i)
        {
            vector<int> temp;
            temp.push_back(1);
            int j;
            for(j=2; j<i; ++j)
            {
                temp.push_back(prev_temp[j-2] + prev_temp[j-1]);
            }
            if (j>1 and j==i)
            {
                temp.push_back(1);
            }
            res.push_back(temp);
            prev_temp = temp;
        }
        return res;
    }
};