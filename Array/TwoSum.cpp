/* Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1]. */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> numbers;
        vector<int> index;
        for (int i =0; i < nums.size();++i)
        {
            int temp = target - nums[i];
            if (numbers.find(temp)!= numbers.end())
            {
                index = {numbers.find(temp)->second, i};
            }
            else
            {
                numbers[nums[i]] = i;
            }
        }
        return index;
    }
};