/* Cousins in Binary Tree
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3: */


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
    bool findpath(TreeNode* root, vector<TreeNode*>& path, int p)
    {
        if (!root)
        {
            return false;
        }
        path.push_back(root);
        if (root->val == p)
            return true;
        if (findpath(root->left, path, p) || findpath(root->right, path, p))
            return true;
        path.pop_back();
        return false;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        vector<TreeNode*> pathp;
        findpath(root, pathp, x);
        
        vector<TreeNode*> pathq;
        findpath(root, pathq, y);
        if (pathq.size()!=pathp.size())
            return false;
        bool res = false;
        for (int i=0;i<pathp.size()-1;++i)
        {
            if (pathp[i] != pathq[i])
            {
                return true;
            }
        }
        return false;
    }
};
Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false