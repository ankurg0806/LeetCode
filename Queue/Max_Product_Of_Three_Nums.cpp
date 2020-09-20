/* Maximum Product of Three Numbers
Given an integer array, find three numbers whose product is maximum and output the maximum product.

Example 1:

Input: [1,2,3]
Output: 6
 

Example 2:

Input: [1,2,3,4]
Output: 24
 */
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        priority_queue<int> q;
        for (auto num: nums)
            q.push(num);
        priority_queue<int, vector<int>, std::greater<int>> q1;
        for (auto num: nums)
            q1.push(num);
        int num1 = q.top();
        q.pop();
        int num2 = q.top();
        q.pop();
        
        int num3 = q1.top();q1.pop();
        int num4 = q1.top();q1.pop();
        return std::max(num3*num4*num1, num1*num2*q.top());
    }
};