/* Given a sorted integer array without duplicates, return the summary of its ranges.

Example 1:

Input:  [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: 0,1,2 form a continuous range; 4,5 form a continuous range.
Example 2:

Input:  [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: 2,3,4 form a continuous range; 8,9 form a continuous range. */

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.empty())
            return res;
        int i=0;
        while (i<nums.size())
        {
            string temp= std::to_string(nums[i]);
            int j=i;
            while (j<nums.size()-1 and (nums[j+1] == nums[j] + 1))
            {
                j++;
            }
            if (j>i)
            {
                temp = temp + "->" + std::to_string(nums[j]);
            }
            res.push_back(temp);
            i = j+1;
        }
        return res;
    }
};