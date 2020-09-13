/* 
84. Largest Rectangle in Histogram
Hard
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
       _
     _| |
|   | | |
|   | | |  _
|_  | | |_| |
| |_| | | | |
|_|_|_|_|_|_|_____________

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3]. 

Example:

Input: [2,1,5,6,2,3]
Output: 10 */

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty())
            return 0;
        int maxArea = 0;
        stack<int> s;
        int i=0;
        int n = heights.size();
        while (i<n)
        {
            if (s.empty() or heights[s.top()] <= heights[i])
            {
                s.push(i++);
            }
            else
            {
                int tp = s.top();
                s.pop();
                int area = heights[tp] * (s.empty() ? i: i - s.top() - 1);
                maxArea = maxArea<area?area:maxArea;
            }
        }
        while (!s.empty())
        {
            int tp = s.top();
            s.pop();
            int area = heights[tp] * (s.empty() ? i: i - s.top() - 1);
            maxArea = maxArea<area?area:maxArea;
        }
        return maxArea;
    }
};