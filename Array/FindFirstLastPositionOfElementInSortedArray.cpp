34. Find First and Last Position of Element in Sorted Array
Medium

Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

class Solution {
public:
    void util(vector<int>& a, int tar, int start, int end, set<int>& s)
    {
        if (start <= end)
        {
            int mid = start + (end - start)/2;
            if (a[mid] == tar)
            {
                s.insert(mid);
                if (mid>start and a[mid-1] == tar)
                    util(a, tar, start, mid -1, s);
                if (mid+1 <= end and a[mid+1] == tar)
                util(a, tar, mid+1, end, s);   
            }
            else if (a[mid]> tar)
                util(a, tar, start, mid-1, s);   
            else
                util(a, tar, mid+1, end, s);         
        }
    }
        
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0;
        set<int> s;
        vector<int> res;
        int end = nums.size()-1;
        util (nums, target, 0, end, s);
        if (s.empty())
        {
            res.push_back(-1);
            res.push_back(-1);
        }
        else
        {
            res.push_back(*s.begin());
                                    res.push_back(*std::prev(s.end()));
        }
        return res;
            
    }
};