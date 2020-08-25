/* Maximum path sum in a binary tree
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42 */

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
    int result;
public:
    int maxPathSumUtil(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int left = maxPathSumUtil(root->left);
        int right = maxPathSumUtil(root->right);
        int maxOfLeftAndRight = std::max(left+root->val, right+root->val);
        int maxAmongLeftRightAndRoot = std::max(root->val, maxOfLeftAndRight);
        int sumIncludingRootLeftAndRight = root->val + left + right;
        int maxAtThisNode = std::max(sumIncludingRootLeftAndRight, maxAmongLeftRightAndRoot);
        result = std::max(result, maxAtThisNode);
        return maxAmongLeftRightAndRoot;
    }
    int maxPathSum(TreeNode* root) {
        result = INT_MIN;
        if (root == nullptr)
            return 0;
        maxPathSumUtil(root);
        return result;
    }
};