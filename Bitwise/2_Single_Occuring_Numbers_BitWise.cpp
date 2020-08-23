/* Single Number III

Solution
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]
Note:

The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity? */

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr = 0,num1=0,num2=0;  // Xor of entire array, the two numbers
        for(int x: nums) xr^=x;   // XOR of two num
        int setBit = 1;   // Let us begin with the first num
        for(int i = 1;i<=31;i++){
            if(xr & setBit) break;    //This is the rightmost set bit   
            setBit<<=1;
        }
		
        for(int x: nums){
            if((x&setBit) == setBit) num1 ^= x;   // this is group A
            else num2 ^= x;   // This is group B
        }
        return {num1,num2};
    }
};