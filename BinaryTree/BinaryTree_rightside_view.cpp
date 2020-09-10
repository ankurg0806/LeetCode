/* Binary Tree Right Side View

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
  
Solution 1 with BFS
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* temp = q.back();
            res.push_back(temp->val);
            int len = q.size();
            for (int i=0;i<len;++i)
            {
                TreeNode* temp = q.front();
                q.pop();
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
        }
        return res;
    }
};

//Solution 2 with DFS i.e. recursion
class Solution {
    vector<int> rightside;
public:
    void helper(TreeNode* root, int level)
    {
        if (level == rightside.size())
        {
            rightside.push_back(root->val);
        }
        if (root->right)
            helper(root->right, level+1);
        if (root->left)
            helper(root->left, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        if (not root)
            return rightside;
        helper(root, 0);
        return rightside;
    }
};