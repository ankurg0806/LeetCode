/* Maximum width of a binary tree
https://www.youtube.com/watch?v=le-ZZSQRebw
Given a binary tree, write a function to get the maximum width of the given tree. The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

It is guaranteed that the answer will in the range of 32-bit signed integer.

Example 1:

Input: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:

Input: 

          1
         /  
        3    
       / \       
      5   3     

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:

Input: 

          1
         / \
        3   2 
       /        
      5      

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
Example 4:

Input: 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7). */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        int result = 1;
        queue<pair<TreeNode*, int>> Q;
        Q.push({root, 0});
        while (not Q.empty())
        {
            int count = Q.size();
            int start = Q.front().second;
            int end = Q.back().second;
            result = max(result, end - start + 1);
            for (int i=0;i<count;++i)
            {
                pair<TreeNode*, int> p = Q.front();
                //Most important line to avoid overflow, at each level the indices are grwoing exponentially and it can cause integer overflow
            //rather than starting the children indices from p.second, what if we start it with zero at each level, i.e suppose we are at level 3
                // idx ideally will start with 3 and can have max value of 6 for right most node and the width will be 6-3+1, but if we consider it to start at 0, and it will end at 3, there is no difference between 3-0+1 and 6-3+1.
                int idx = p.second - start;
                Q.pop();
                if (p.first->left)
                {
                    Q.push({p.first->left, 2*idx+1});
                }
                if (p.first->right)
                {
                    Q.push({p.first->right, 2*idx+2});
                }
            }
        }
        return result;
    }
};