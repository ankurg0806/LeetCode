/* 250. Count Univalue Subtrees

Given the root of a binary tree, return the number of uni-value subtrees.

A uni-value subtree means all nodes of the subtree have the same value.

      5
	/   \
   1     5
  / \     \
 5   5     5
Input: root = [5,1,5,5,5,null,5]
Output: 4

Input: root = [5,5,5,5,5,null,5]
Output: 6 */

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
    bool univalUtil(TreeNode* root, int& count)
    {
        if (!root)
            return true;
        
        bool leftUnival = univalUtil(root->left, count);
        bool rightUnival = univalUtil(root->right, count);
        if (leftUnival and rightUnival)
        {
            if ((root->left and root->val != root->left->val) or
                (root->right and root->val != root->right->val))
                {
                    return false;
                }
                else
                {
                    count++;
                    return true;
                }
        }
        return false;
    }
    int countUnivalSubtrees(TreeNode* root) {
        int count=0;
        univalUtil(root, count);
        return count;
    }
};