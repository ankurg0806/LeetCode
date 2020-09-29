/* 42. Trapping Rain Water
Hard

Share
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

Example:

      |
	  |
	  |
	  |              _
	  |      _      | |_   _
	  |  _  | |_   _| | |_| |_
	  |_|_|_|_|_|_|_|_|_|_|_|_|_____________
Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6 */

class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if (height.empty())
            return 0;
        vector<int> leftHeight(len,0);
        vector<int> rightHeight(len,0);
        leftHeight[0] = height[0];
        rightHeight[len-1] = height[len-1];
        for (int i=1; i<len; ++i)
        {
            leftHeight[i] = max(height[i], leftHeight[i-1]);
        }
        for (int i=len -2; i>=0; --i)
        {
            rightHeight[i] = max(height[i], rightHeight[i+1]);
        }
        int trapSum = 0;
        for (int i=1;i<len-1; ++i)
        {
            trapSum = trapSum + min(leftHeight[i], rightHeight[i]) - height[i];
        }
        return trapSum;
    }
};