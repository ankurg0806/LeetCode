/* 85. Maximal Rectangle
Hard

Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example:

Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        int maxArea = 0;
        stack<int> s;
        int i=0;
        int n = heights.size();
        while (i<n)
        {
            if (s.empty() or heights[s.top()] <= heights[i])
                s.push(i++);
            else
            {
                int tp = s.top();
                s.pop();
                
                int area = heights[tp] * (s.empty()? i : i - s.top() - 1);
                maxArea = maxArea<area?area:maxArea;
            }
        }
        while (!s.empty())
        {
            int tp = s.top();
                s.pop();
                
                int area = heights[tp] * (s.empty()? i : i - s.top() - 1);
                maxArea = maxArea<area?area:maxArea;
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        int maxArea = 0;
        vector<int> heights(matrix[0].size(),0);
        
        for (int i=0;i<matrix.size();++i)
        {
            for (int j=0;j<matrix[0].size();++j)
            {
                heights[j] = matrix[i][j] == '0'?0:heights[j]+1;
            }
            maxArea = std::max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }
};