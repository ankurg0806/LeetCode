/* Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:

Input:nums = [1,1,1], k = 2
Output: 2
 

Constraints:

The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].

The solution is based on taking cumulative sums at each step and an important property i.e.

[1, 3, 4, 7, -2, -3, 5, 4]

[1, 4, 7, 14, -12, -9, 14, 18]

If sum_j is the sum of numbers till index j starting at index 0
    and sum_i is the sum of numbers till index i starting from 0 and i<j
    sum_ij will be sum_j - sum_(i-1) */
    
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap;
        int curr_sum = 0;
        int count_of_subarrays = 0;
        for (auto num: nums)
        {
            curr_sum += num;
            if (curr_sum == k)
            {
                count_of_subarrays++;
            }
            if (hashmap.find(curr_sum-k) != hashmap.end())
            {
                count_of_subarrays += hashmap[curr_sum - k];
            }
            hashmap[curr_sum]++;
        }
        return count_of_subarrays;
    }
};

// Time complexity is O(n) as I am traversing the array only once
// space complexity is O(n)