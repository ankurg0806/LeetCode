/* Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
 */

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
    int util(TreeNode* root, TreeNode* child)
    {
        if (not root)
            return 0;
        if (not child)
            return 0;
        int sum = util(child, child->left) + util(child, child->right);
        if (not child->left and not child->right and child == root->left)
            sum += child->val;
        return sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if (not root)
            return 0;
        sum += util(root, root->left);
        sum+= util(root, root->right);
        return sum;
    }
};