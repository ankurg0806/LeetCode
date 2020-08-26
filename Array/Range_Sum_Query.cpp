/* Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.

Example:

Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
 

Constraints:

The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.
0 <= i <= j <= nums.length - 1 */


class NumArray {
    vector<int> _nums;
    vector<int> _numsum;
    public:
    NumArray(vector<int>& nums) : _nums(nums),_numsum(nums){
        for (int i=1;i<nums.size();++i)
        {
            _numsum[i] = _numsum[i] + _numsum[i-1];
        }
    }
    
    void update(int i, int val) {
        int temp = _nums[i];
        _nums[i] = val;
        for (int j=i;j<_nums.size();++j)
            _numsum[j] = _numsum[j] + val - temp; 
    }
    
    int sumRange(int i, int j) {
        if (i==0)
        {
            return _numsum[j] ;
        }
        return _numsum[j]-_numsum[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */