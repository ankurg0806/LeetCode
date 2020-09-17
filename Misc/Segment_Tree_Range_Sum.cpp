/* 307. Range Sum Query - Mutable
Medium

Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.

Example:

Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
 

Constraints:

The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.
0 <= i <= j <= nums.length - 1
 */

class NumArray {
    vector<int> tree;
    int siz;
    public:
    NumArray(vector<int>& nums) : tree(2*nums.size(),0), siz(nums.size()){
        for (int i=0;i<nums.size();++i)
        {
            tree[siz + i] = nums[i];
        }
        for (int i=siz-1;i>0;--i)
        {
            tree[i] = tree[2*i] + tree[2*i + 1];
        }
    }
    
    void update(int i, int val) {
        i = i + siz;
        tree[i] = val;
        while (i>0)
        {
            int left = i;
            int right = i;
            if (i % 2 == 0) {
                right = i + 1;
            } 
            else {
                left = i - 1;
            }
            tree[i/2] = tree[left] + tree[right];
            i = i/2;
        }
    }
    
    int sumRange(int l, int r) {
        l = l + siz;
        r = r + siz;
        int sum=0;
        while (l<=r)
        {
          if ((l % 2) == 1) {
           sum += tree[l];
           l++;
        }
        if ((r % 2) == 0) {
           sum += tree[r];
           r--;
        }
        l /= 2;
        r /= 2;
    }
    return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */